// PC13接按键，PB0-PB7接数码管段选abcdefgh，PA0-PA3接数码管位选
//按键闭合，LED顺时针点亮；按键再闭合，LED逆时针点亮

#include "stm32f10x.h"
void Delay(vu32 nTime);
void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);
void EXTI_Configuration(void);
u8 dat;
u8 i;
u8 num;
int main(void)
{
    RCC_Configuration();
    GPIO_Configuration();
    EXTI_Configuration();
    NVIC_Configuration();
    GPIOA->ODR = 0xffff;
    while (1)
    {
        switch (num)
        {
        case 0:
            dat = ~(1 << i);  // 00000001-->11111110, ~表示取反,00000010-->11111101
            GPIOB->ODR = dat; // PB7-PB0=11111110B
            i++;
            if (i >= 6)
            {
                i = 0;
            }
            Delay(200000);
            break;
        case 1:
            dat = ~(0x20 >> i); // 0010 0000-->1101 1111
            GPIOB->ODR = dat;   // PB7-PB0=01111111B,直接写端口寄存器
            i++;
            if (i >= 6)
            {
                i = 0;
            }
            Delay(200000);
            break;
        }
    }
}
void RCC_Configuration(void) //配置时钟的函数
{
    SystemInit();
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE); //使能端口时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);                         //使能AFIO的时钟
}

void GPIO_Configuration(void) //配置GPIO, PA7-PA0,PC9-PC6推挽输出，PC13上拉输入
{
    GPIO_InitTypeDef GPIO_InitStructure; //定义结构体

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void Delay(u32 nCount) //延时函数
{
    for (; nCount != 0; nCount--)
        ;
}
void EXTI_Configuration(void) //配置外部中断源
{
    EXTI_InitTypeDef EXTI_InitStructure;                    //声明外部中断初始化结构体
    EXTI_InitStructure.EXTI_Line = EXTI_Line13;             //外部中断线Line13
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;     // 选择中断模式
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;               //使能中断
    EXTI_Init(&EXTI_InitStructure);                         //初始化外部中断

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13); // PC13配置为外部中断源
}

void NVIC_Configuration(void) //嵌套向量中断初始化
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);           //中断优先级分组配置分组1，2个抢占优先级，8个从优先级
    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;      // EXTI15_10中断源
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //占先优先级设定，取值为0-1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;        //从优先级设定，取值为0-7
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}
//外部中断源15-10的中断处理子程序,每个中断子程序名是系统分配好的，不能自己起名
void EXTI15_10_IRQHandler(void)
{
    if (EXTI_GetITStatus(EXTI_Line13) != RESET)
    {
        Delay(20000);
        num++;
        if (num == 2)
        {
            num = 0;
        }
    }
}
