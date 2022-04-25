.data
str1: .string "GCD value of "
str2: .string " and "
str3: .string " is "

.text

main:
    li a0,4 #n1
    li a1,8 #n2
    mv t5,a0
    mv,t6,a1
    addi sp,sp,-8
    
    sw sp,(0)ra
    jal ra,gcd
    
    
    jal ra,print
    
    
    li a7,10
    ecall
    
    
    
gcd:
    mv t0,a0
    mv t1,a1
    jal ra,mod
    mv a0,t1
    mv a1,t0    
    bne a1,zero,gcd
    jr x1
    
    
        

mod:
    

    sub t0,t0,t1
    bge t0,t1,mod 
    
    add t0,t0,t1
    beq t0,t1,myadd
    ret
    
myadd:
    sub t0,t0,t1
print:
    
        mv t0, a0
        mv t1, a1
        
        la a0, str1
        li a7, 4
        ecall
        mv a0, t5
        li a7, 1
        ecall
        la a0, str2
        li a7, 4
        ecall
        mv a0, t6
        li a7, 1
        ecall
        la a0, str3
        li a7, 4
        ecall
        mv a0, t1
        li a7, 1
        ecall
        

        
        
        
            
    
    