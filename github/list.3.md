# 数据和c
***
## 8. 
在美国的体积测量系统中，1品脱等于2杯，1杯等于8盎司，1盎司等于2大汤勺，1大汤勺等于3茶勺。编写一个程序，提示用户输入杯数，并以品脱、盎司、汤勺、茶勺为单位显示等价容量。思考对于该程序，为何使用浮点类型比整数类型更合适？
### 答案
```c
#include<stdio.h>
int main()
{
    double cup,ping,ang,tang,cha;
    printf("Please getput number cup:");
    scanf("%lf",&cup);
    ping=cup/2;
    ang=8*cup;
    tang=2*ang;
    cha=3*tang;
    printf("%.3lf\n%.3lf\n%.3lf\n%.3lf\n",ping,ang,tang,cha);
    return 0;
}
```
#### 实际中杯不一定是整数，使用整数会产生较大误差，浮点相对来说误差更小。
***
## 6. 
1个水分子的质量约为3.0×10^{-23}克。1夸脱水大约是950克。编写一个程序，提示用户输入水的夸脱数，并显示水分子的数量。
### 答案
```c
#include<stdio.h>
int main()
{
    printf("Please getput number kuatuo:");
    double n;
    scanf("%lf",&n);
    double num=(950*n)/3.0e-23;
    printf("%e",num);
    return 0;
}
```
***
## 3. 
编写一个程序，发出一声警报，然后打印下面的文本：
 
plaintext
  
Startled by the sudden sound, Sally shouted,
"By the Great Pumpkin, what was that!"
### 答案
```c
include<stdio.h>
int main()
{
    printf("\a");
    printf("plaintext\n\n");
    printf("Startled by the sudden sound,Sally shouted,\n\"By the Great Pumpkin,what was that!\"");
    return 0;
}
```
***
## 4. 
编写一个程序，读取一个浮点数，先打印成小数点形式，再打印成指数形式。然后，如果系统支持，再打印成p记数法（即十六进制记数法）。按以下格式输出（实际显示的指数位数因系统而异）：
 
plaintext
  
Enter a floating-point value: 64.25
fixed-point notation: 64.250000
exponential notation: 6.425000e+01
p notation: 0x1.01p+6
### 答案
```c
#include<stdio.h>
int main()
{
    printf("plaintext\n\nEnter a floating-point value:");
    double n;
    scanf("%lf",&n);
    printf("fixed-point notation:%lf\n",n);
    printf("exponential notation:%e\n",n);
    printf("p notation:%a\n",n);
    return 0;
    
}
```