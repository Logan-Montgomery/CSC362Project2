unsigned long __stdcall Fork(unsigned long arg) {
    void* stackptr = (void*)&arg;
    unsigned long ret;
    __asm {
        mov eax, 128H;      // We want to call Syscall 128H, so move 128H to EAX register
        mov edx, stackptr;  // Move stackptr to EDX register
        int 2EH;            // Trigger interrupt 2EH (Windows Syscall Interrupt)
        mov ret, eax;       // Return value is stored in EAX, so move EAX register to ret variable
    }
    return ret;
}