; 3 Aula Pratica de Microprocessadores
;
; Objetivos: 
; 1 - Apreender a utilizar as instrucoes de I/O e saber a diferenca para  
;     as instrucoes de memoria.
;
; 2 - Dominar a tecnica do uso de tabelas indexadas pelo operando em assembly.
;
; Considere o problema abaixo:
;
; Escreva um programa assembly 8088 p/ ambiente MSDOS, que le da memoria
; 4 digitos BCD (1 por byte, no nibble LSB) a partir da area de constantes,
; e os converte p/ codigo de 7 segmentos (segundo a convencao abaixo) e joga
; um por um nas 4 portas de saida a partir do endereco 500H.
;          a
;          -                 Convencao:
;       f | | b
;          - g                 D7 D6 D5 D4 D3 D2 D1 D0
;       e | | c  . pt          pt  g  f  e  d  c  b  a
;          -
;          d
;
        org     0100H 
        section .text
START:
; da um prompt para o usuario
        lea     dx,[msg1]
        mov     ah,9
        int     21H
; aponta memoria com digitos BCD
        lea     si,[dados]
; carrega contador com n. de digitos a processar
        mov     cx,4
; aponta primeira porta de saida do digito convertido
        mov     dx,500H
; le um caracter da memoria
prox:   mov     al,[ds:si]
        inc     si           ;aponta proximo digito a converter
; endereco tabela e converte BCD para 7 segmentos
        lea     di,[tab]
        mov     ah,0
        add     ax,di
        mov     di,ax        
        mov     al,[ds:di]
; joga digito convertido na porta de saida e aponta proxima porta
        out     dx,al
        inc     dx           ;incrementa endereco da porta
; se nao acabou volta e faz o proximo caracter
        loop    prox
; acabou - mostra mensagem de saida na tela
        mov     ah,9
        lea     dx,[msg2]
        int     21H
; termina o programa e volta o controle para o DOS
Done:   mov  ah,4ch          ;DOS terminate program function #
        int  21h             ;terminate the program
;        
        section .data        ;declaracao de constantes
;
msg1    db      'Programa Exemplo 1 ',13,10,'$'
msg2    db      'Programa Exemplo 1 executou OK',13,10,'$'
dados   db      04h, 09h, 02h, 01h
;                0   1   2   3   4   5   6   7   8   9    <- Em BCD
tab     db      3FH,06H,5BH,4FH,66H,6DH,7CH,07H,7FH,67H ; <- Em 7 seg.
nl      db      13,10,'$'
;
        section .bss         ;declaracao de variaveis
; ----- nao utilizado neste programa
;
        END



