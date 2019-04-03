Pl011 Uart notes.
    1. IP clock has fixed frequency of 48MHz;
    2. IBRD, FBRD and LCRH are one big register and it is latched on LCRH write operation.
        Thus LCRH has to be written after baudrate tuning.

QEMU launch.

    qemu-system-aarch64 -M raspi3 -kernel kernel8.img -serial stdio -d in_asm
        -M -- machine type (raspberry pi 3 obviously)
        -kernel -- path to a kernel image
        -serial -- use pl011 uart as serial console (stdio). Input output to shell
        -d -- deamonize after startup (detach). With in_asm parameter shows assembly output to shell