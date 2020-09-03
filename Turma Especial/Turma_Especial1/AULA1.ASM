; 1 Aula Pratica de Microprocessadores
;
; Objetivos: 
; 1 - Aprender a utilizar o montador assembly NASM para gerar codigo em modo
;     real 8088, para ambiente MsDos compat¡vel, no formato .COM
;     Para isto veja a sintaxe de uso do montador no arquivo C.BAT
;     Utilize assim:
;     C MEUPROG onde MEUPROG ‚ o nome do seu programa.
;     Nao coloque .asm ou qualquer outra coisa.
;
; 2 - Atraves do exemplo a seguir, aprender o formato de montagem do NASM.
;
; 3 - Conhecer as funcoes do BIOS e do DOS que permitem:
;     - limpar a tela
;     - posicionar o cursor
;     - escrever um caracter na tela
;     - escrever uma frase na tela
;     - ler um caracter do teclado com eco
;     - ler um caracter do teclado sem eco
;     - ler uma frase do teclado
;
        org     0100H                 ;pseudo instrucao obrigatoria para
                                      ;um programa .COM onde 0100H e' o
                                      ;load address (endereco de carga do
                                      ;programa na memoria
        section .text                 ;apos esta pseudo instrucao coloque
                                      ;o codigo do seu programa
START:                                ;aqui inicia a execucao do programa
                                      ;este e' o entry point ou start address
;
; Observe no programa abaixo que uma linha de codigo assembly tem formato:
; LABEL     INSTRUCAO     OPERANDOS     COMENTARIO
; Montadores mais evoluidos aceitam apenas um espaco entre os campos acima
; porem a listagem do programa fica ilegivel e "feia".
; Vamos adotar o padrao dos montadores mais rigidos. Assim seu codigo ficara
; legivel e compilara em qualquer montador. As regras sao:
; um ponto virgula faz com que o resto da linha seja comentario
; LABEL's comecam na coluna 1 obrigatoriamente
; os meneumonicos das instrucoes devem comecar na coluna 9
; os operandos comecam na coluna 17
; os comentarios podem comecar um espaco apos o ultimo operando
;
; limpa a tela com funcao do BIOS porque o DOS nao tem essa funcao
        mov     ax, 0003H
        int     10H          ;veja pg. 194 do livro texto
; posiciona cursor com funcao do BIOS porque o DOS nao tem essa funcao
        mov     ah, 2        ;numero da funcao posiciona cursor da INT 10
        mov     dh, 4        ;5 linha (comeca de zero)
        mov     dl, 9        ;10 coluna (comeca de zero)
        mov     bh, 0        ;numero da pagina de video
        int     10H          ;veja pg. 195 do livro texto
; escreve um caracter na tela
        mov     ah, 2        ;funcao escreve um caracter na tela do DOS
        mov     dl, '*'      ;dl leva o caracter a escrever
        int     21H          ;veja pg. 215 do livro texto
; escreve uma frase na tela 
        lea     dx, [msg1]
        mov     ah, 9
        int     21H
; escreve uma frase na tela pedindo uma resposta
        lea     dx, [msg2]
        mov     ah, 9
        int     21H
; le um caracter na tela com eco
le:     mov     ah, 1        ;funcao le um caracter com eco do DOS
        int     21H          ;veja pg. 214 do livro texto
        or      al, al       ;seta flags
        jz      le           ;se zero, le novamente codigo tecla especial
; testa se tecla lida esta entre 0 e 9
        cmp     al, '0'      ;e' igual a zero
        jb      le           ;e' menor que zero. volta a ler tecla
        cmp     al, 3AH      ;e' igual a '9'+1
        jnc     le           ;e' maior que nove. volta a ler tecla
; escreve uma frase na tela pedindo uma senha
        lea     dx, [msg3]
        mov     ah, 9
        int     21H
; le um caracter do teclado sem eco
        mov     ah, 8        ;funcao le um caracter sem eco do DOS
        int     21H          ;veja pg. 218 do livro texto e tambem as
                             ;funcoes 6, e 7
; escreve uma frase e mostra caracter lido sem eco
        push    ax           ;salva caracter lido sem eco na pilha
        lea     dx, [msg4]   ;escreve mensagem
        mov     ah, 9
        int     21H
        pop     ax           ;recupera caracter da pilha
        mov     ah, 2        ;mostra caracter lido sem eco
        mov     dl, al
        int     21H
; le uma frase do teclado
        lea     dx, [msg5]   ;escreve prompt na tela pedindo frase
        mov     ah, 9
        int     21H
        lea     di, [buf]     ;aponta o buffer onde sera lido a frase
        mov     byte [di], 11 ;indica para ler no maximo 10 caracteres
        mov     dx, di
        mov     ah, 0AH       ;funcao le string do DOS
        int     21H           ;veja pg. 219 do livro texto
; termina o programa e volta o controle para o DOS
Done:   mov  ah,4ch          ;DOS terminate program function #
        int  21h             ;terminate the program
;        
        section .data        ;apos esta pseudo-instrucao declare suas 
                             ;constantes
;
msg1    db      ' Limpei a tela e posicionei o cursor na linha 5 coluna 10,'
        db      13,10,'           escrevi um *, e depois esta frase.$'
; Observe nas linhas anteriores o uso dos caracteres ASCII 13 e 10 para
; voltar o cursor e saltar linha.
; o 13 e' o CR (Carriage Return - 0D em hexa)
; o 10 e' o LF (Line Feed - 0A em hexa)
msg2    db      13,10,10,'Opcao (Entre um digito de 0 a 9) : $'
msg3    db      13,10,10,'Entre com a senha (1 digito) : $'
msg4    db      13,10,10,'Voce digitou e eu li sem eco : $'
msg5    db      13,10,10,'Entre uma frase de ate 10 caracteres : $'
;
        section .bss         ;apos esta pseudo-instrucao declare suas 
                             ;variaveis
buf     resb    13
;
        END



