# Floating-Numbers-Generator
Genearte IEEE 754 Floating-Point Numbers as Samples for Scientific Researches

## Generation Rule
 - Sign bit can be either 0 or 1.
 - Exponent bits are traversed.
 - Fraction bits are divided into two parts.Fisrt n bits of fraction are traversed and the rest bits are randomly generated.

## How To Use
command:
```
 $ gcc double_point_generator.c -o double_point_generator.out
 $ ./double_point_generator.out
```


# 浮点数生成器
生成IEEE754标准的浮点数作为科学研究的测试样本

## 生成规则
 - 符号位可以是0也可以是1
 - 指数位遍历
 - 小数位分成两个部分，前n位遍历，剩余的随机生成

## 如何使用
命令:
```
 $ gcc double_point_generator.c -o double_point_generator.out
 $ ./double_point_generator.out
```


