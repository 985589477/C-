//
//  main.c
//  C算法合集
//
//  Created by 李璇 on 2017/10/12.
//  Copyright © 2017年 Lxxxxx. All rights reserved.
//

#include <stdio.h>
#include <string.h>
/*
算法1
    问题:
 题目：古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔
 子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数
 为多少？
 问题分析: 1 1 2 3 5 8 13
 */
void algorithm1();

/*
算法2
 问题
 题目：判断101-200之间有多少个素数，并输出所有素数。
 问题分析:  素数的概念:只能被1或本身整除的数
 */
void algorithm2();

/*
 算法3
 问题
 题目:打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位
 数字立方和等于该数本身。例如：153是一个“水仙花数”，因为153=1的三次方
 ＋5的三次方＋3的三次方。
 问题分析:  首先3位数 范围为100 - 999
          其次 个、十、百位 的3次方相加为该数
 */
void algorithm3();

/*
 算法4
 问题
 题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
 问题分析: 首先 分解为因数  其次 质数
 */
void algorithm4();

/*
 算法5
 问题
 题目:利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。
 问题分析: 条件运算符 a>b? a:b;
 */
void algorithm5();

/*
 算法6
 问题
 题目:输入两个正整数m和n，求其最大公约数和最小公倍数。
 问题分析: 最大公约数:能同时被两个数整除的最大数字
          最小公倍数:求一个最小数可以同时整除这两个数;
 */
void algorithm6();

/*
 算法7
 问题
 题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数
 问题分析:利用遍历
 */
void algorithm7();

/*
 算法8
 问题
 题目:求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
 问题分析:
 */
void algorithm8();


int main(int argc, const char * argv[]) {
    
    algorithm8();
    
    return 0;
}

void algorithm1(){
    //兔子1 兔子2
    int rabbit1 = 1,rabbit2 = 1;
    //记录要计算多少个月后的数量
    int month;
    printf("请输入过了多少个月:");
    scanf("%d",&month);
    //创建一个变量 用来记录循环条件
    int i = 0;
    //做循环计算兔子数量
    while (i < month) {
        //循环条件
        i++;
        //根据问题分析计算 前两个月不具备生育能力了，所以分别为1
        if (i < 3) {
            printf("1");
        }else{
            //求总兔子数量 根据规律 每个新月份的兔子数量为前两个月的兔子数量总和
            int allRabbit = 0;
            allRabbit = rabbit1 + rabbit2;
            if (i % 2 == 0) {
                rabbit2 = allRabbit;
            }else{
                rabbit1 = allRabbit;
            }
            printf("%d",allRabbit);
        }
    }
};

void algorithm2(){
    //用来存储范围 最大值和最小值
    int num1=0,num2=0;
    printf("请输入2个数确定范围:");
    scanf("%d%d",&num1,&num2);
    while (num1 != num2) {
        //定义变量 用来存放最小数字 并且通过判断来确定最小的以方便 ++
        int min = 0;
        if (num1 == num2) {
            break;
        }
        if (num1 < num2) {
            min = num1;
            num1++;
        }else{
            min = num2;
            num2++;
        }
        //定义标识符
        int isDivisible = 0;
        //通过循环遍历是否能被前2-9所整除 如果可以，则退出 状态通过isOk记录
        for (int i = 2; i < min; i++) {
            if (min % i == 0) {
                isDivisible = 0;
                break;
            }else{
                isDivisible = 1;
            }
        }
        //如果为可以整除，则进行下一次循环
        if (isDivisible == 0) {
            if (min == 2) {
                isDivisible = 1;
            }else{
                continue;
            }
        }
        
        printf("%d\n",min);
    }

}

void algorithm3(){
    int i = 100;
    while (i < 1000) {
        //获取个位
        int digit = i % 10;
        //获取十位数
        int tens = (i % 100) / 10;
        //获取百位数
        int hundred = (i % 1000) / 100;
        int sum = (digit * digit * digit) + (tens * tens * tens) + (hundred * hundred * hundred) ;
        //判断是否相等
        if (sum == i) {
            printf("百位%d,十位%d,个位%d\n",hundred,tens,digit);
            printf("%d\n",i);
        }
        i++;
    }
}

void algorithm4(){
    int arr[100] = {0};
    int index = 0;
    int round = 0;
    printf("请输入一个正整数:");
    scanf("%d",&round);
    //得到该数以内的所有质数
    for (int i = 2; i < round; i++) {
        int j = 2;
        int isOk = 0;
        
        while (j < i) {
            if (i % j == 0) {
                isOk = 0;
                break;
            }else{
                isOk = 1;
            }
            j++;
        }
        if (isOk == 0) {
            //因为2也是质数，所以需要单独判断
            if (i == 2) {
                isOk = 1;
            }else{
                continue;
            }
        }
        arr[index] = i;
        index++;
    }
    //当前已经拿到所有质数存放在arr中 只需要计算哪些相乘可以得出结果
    int j = 1;
    while (j) {
        int isOver = 0;
        for (int i = 0; i < index; i++) {
            if(round % arr[i] == 0){
                printf("%d\n",arr[i]);
                round = round / arr[i];
                if (round == 1) {
                    isOver = 1;
                    break;
                }
            }else{
                continue;
            }
        }
        if (isOver) {
            break;
        }
    }
    
    
}

void algorithm5(){
    int sum = 0;
    printf("请输入你的成绩:");
    scanf("%d",&sum);
    char *char1 = "";
    //嵌套 条件表达式
    char1 = (sum >= 90) ? "A" : ((sum >= 60) ? "B":"C");
    printf("%s\n",char1);
}

void algorithm6(){
    //输入两个正整数 m n
    int m = 0,n = 0;
    printf("请输入两个数:");
    scanf("%d%d",&m,&n);
    //计算出m n中最小的数字
    int min = 0;
    min = m < n ? m:n;
    //通过遍历来找到同时可以被整除的数字
    while (min > 1) {
        if ( m % min == 0 && n % min == 0) {
            printf("最大公因数:%d\n",min);
            break;
        }
        min--;
    }
    int max = 0;
    max = m > n ? m:n;
    while (max) {
        if (max % m == 0 && max % n == 0) {
            printf("最小公倍数:%d\n",max);
            break;
        }
        max++;
    }
}

void algorithm7(){
    //记录个数
    int charCount=0,sapceCount=0,numberCount=0,ohtersCount=0;
    char c;
    printf("请输入字符串:");
//    scanf("%s",string);
    while( (( c = getchar()) != '\n')){
        if ((c >= 'a' && c <= 'z') ||  (c >= 'A' && c <= 'Z')){
            charCount++;
        }else if (c == ' ') {
            sapceCount++;
        }else if (c >= '0' && c <= '9'){
            numberCount++;
        }else{
            ohtersCount++;
        }
    }
    printf("字符长度:%d,空格长度:%d,数字长度:%d,其他长度:%d",charCount,sapceCount,numberCount,ohtersCount);
    
}

void algorithm8(){
    //要计算的数字。  要计算的次数
    int number = 0,count = 0;
    printf("请输入一个要计算的数:");
    scanf("%d",&number);
    printf("请输入要计算的次数:");
    scanf("%d",&count);
    //作为循环条件。作为结果
    int i = 1,  result = 1;
    //循环要计算的次数
    while (i <= count) {

        result *= number;
        i++;
    }
    printf("number = %d\n",result);
}









