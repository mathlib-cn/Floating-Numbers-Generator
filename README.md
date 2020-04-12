# Floating-Numbers-Generator
Genearte IEEE 754 Floating-Point Numbers as Samples for Scientific Researches

## Generation Rule
 - Sign bit can be either 0 or 1.
 - Exponent bits are traversed.
 - Fraction bits are divided into two parts.Fisrt n bits of fraction are traversed and the rest bits are randomly generated.
 - The output consists of three parts,respectively represents sign,exponent and fraction in decimal form.

## How To Use
command:
```
 $ gcc double_point_generator.c -o double_point_generator.out
 $ ./double_point_generator.out
```


# 浮点数生成器
生成IEEE754标准的浮点数作为科学计算的测试样本

## 生成规则
 - 符号位可以是0也可以是1
 - 指数位遍历
 - 小数位分成两个部分，前n位遍历，剩余的随机生成
 - 输出结果由符号位、指数位和小数位三个部分组成，它们以十进制形式表示

## 如何使用
命令:
```
 $ gcc double_point_generator.c -o double_point_generator.out
 $ ./double_point_generator.out
```


