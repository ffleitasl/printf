# Ft_Printf - @42Born2Code

![Screenshoot](https://github.com/freddyfleitas/ftprintf_42/blob/master/ft_printf.png)

## Table of Contents

- [What Is This?](#what-is-this)
- [Key Considerations](#key-considerations)
- [My Experience](#my-experience)
- [Extra](#extra)

## ¿WHAT IS THIS?

That was my initial reaction upon encountering the prototype of the function for the first time.
```
int ft_printf(char *, …)
```
However, as I delved into it, everything began to make sense. Here are some useful resources to take your first steps in the project and explore the world of variadic functions.

- [How to create variadic functions](https://youtu.be/3iX9a_l9W9Y)
- [Review of va_list and examples](https://youtu.be/oDC208zvsdg)
- [Manual of stdarg.h library](https://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdarg.h.html)

## Key Considerations

### First Parameter:

Although it may be confusing that the first parameter has no name, it's essential to note that any name can be used. However, in these projects, it's common to refer to it as "format."

### Function Prototype:

The function prototype is of type int. When implementing the code, it's crucial to consider that, in addition to printing on the screen, it must return the number of characters printed. You can try the following:

```
printf("\nNumber of characters printed: %d", printf("Hello World"));
```
 ## My Experience

My first day with ft_printf was rewarding. I went home with a function that printed characters and strings. However, I had defined auxiliary functions as int, causing issues later. I recommend defining functions as void from the start and adding an int pointer to the parameters. So, remember ...

### Everything start with the Ft_Putchar

Adding an int pointer count to ft_putchar allows us to increment the pointer's value every time we print something. We'll use ft_putchar in each function to display the desired element on the screen.

```c
void ft_putchar(char c, int *count) {
    if (write(1, &c, 1) == -1) {
        *count = -1;
        return;
    } else {
        *count += 1;
    }
}
```
The above is sufficient to start implementing the code and encompasses what I wish I had known before starting.

## Extra

Using %p may seem complicated, but by choosing the correct data type, you can achieve it easily.

**HINT** Unsigned long long is the answer.

 

