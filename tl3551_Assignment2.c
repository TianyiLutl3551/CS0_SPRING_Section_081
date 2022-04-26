name: Tianyi Lu

NetId:tl3551



### 1.

```c
#include<stdio.h> 

int fun(int x){
	if(x == 1)return 1;
	if(x == 2) return 1;
	return fun(x-1) + fun(x-2);
}
 
void main(){
	int y = fun(3);
	printf("%d\n",y);
}
```



The test result is :

![image-20220425222016242](https://tva1.sinaimg.cn/large/e6c9d24egy1h1mbxvwmxoj212z0u00tu.jpg)

### 2.

the main function

![image-20220425222849608](https://tva1.sinaimg.cn/large/e6c9d24egy1h1mc6vd6ovj21ck0maq6e.jpg)

![image-20220425223822121](https://tva1.sinaimg.cn/large/e6c9d24egy1h1mcghgikrj214r0u0adl.jpg)

The fun funtion

![image-20220425223228440](https://tva1.sinaimg.cn/large/e6c9d24egy1h1mcadree2j21cd0u0te3.jpg)

### Explain explain some lines of assembly code of the main function

1. 0x400578 <main>:	push   %rbp

   This is the beginning of main function, push register %rbp to the stack.

2. 0x400579 <main+1>:	mov    %rsp,%rbp

   Assigning %rsp to %rbp

3. 0x40057c <main+4>:	sub    $0x10,%rsp

   %rsp is the stack top pointer, falling 10 indicates reserved space.

4. 0x400580 <main+8>:	mov    $0x3,%edi

   Put the integer 3 into the register edi

5. 0x400585 <main+13>:	callq  0x40052d <fun>

   Calling the <fun> function

6. 0x400590 <main+24>:	mov    %eax,%esi

   Assigning %eax to %esi

7. 0x40059c <main+36>:	callq  0x400410 <printf@plt>

   Calling the printf function

8. 0x4005a1 <main+41>:	leaveq

   The fun function returns

9. 0x4005a2 <main+42>:	retq

   The fun function returns

### Explain explain some lines of assembly code of the fun function

1. 0x40052d <fun>:	push   %rbp

   This is the beginning of fun function, push register %rbp to the stack.

2. 0x40052e <fun+1>:	mov    %rsp,%rbp

   Assigning %rsp to %rbp

3. 0x400531 <fun+4>:	push   %rbx

   Push register %rbx to the stack.

4. 0x400532 <fun+5>:	sub    $0x18,%rsp

   %rsp is the stack top pointer, falling 18 indicates reserved space.

5. 0x400536 <fun+9>:	mov    %edi,-0x14(%rbp)

   Save the value in register edi in the stack frame.

6. 0x400539 <fun+12>:	cmpl   $0x1,-0x14(%rbp)

   Compare the number of %rsp address with 1

7. 0x40053d <fun+16>:	jne    0x400546 <fun+25>

   Jump to <fun+52>

8. 0x400546 <fun+25>:	cmpl   $0x2,-0x14(%rbp)

   Compare the number of %rsp address with 2

9. 0x40054a <fun+29>:	jne    0x400553 <fun+38>

   Jump to <fun+38>

10. 0x400559 <fun+44>:	mov    %eax,%edi

    Assign %eax to %edi

11. 0x400560 <fun+51>:	mov    %eax,%ebx

    Assign %eax to %ebx

