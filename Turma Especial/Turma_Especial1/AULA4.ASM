; 2 Aula Pratica de Microprocessadores
; Compile com : cne aula4
;               link aula4
;
; Objetivos: 
; 1 - Apreender a gerar um arquivo no formato .EXE a partir do programa  
;     aula2.asm. 
;
; 2 - Apreender a diferenca entre codigo intra-segmento e codigo 
;     inter-segmento. 
;
;     - rotina exibe menu -> O texto de um menu de opcoes como do exemplo
;                            abaixo, devera estar na area de constantes.
;                            um trecho de codigo devera aponta-lo com si
;                            e exibi-lo na tela, depois de te-la limpado.
;
;                 Cadastro de alunos
;
;         1 - Incluir
;         2 - Excluir
;         3 - Alterar
;         4 - Consultar
;         5 - Sair
;
;         Opcao: _
;
;
;     - rotina le opcao -> Posiciona o cursor em frente o texto Opcao : _
;                          e le tecla sem eco ate ser digitado um numero
;                          entre 1 e 5. O numero entao e' ecoado na tela,
;                          o programa encerra e volta para o DOS.
;
; Cria o segmento de codigo
        segment code                  ;apos esta pseudo instrucao coloque
                                      ;o codigo do seu programa
;
..start:                              ;aqui inicia a execucao do programa
                                      ;este e' o entry point ou start address
                                      ;ATENCAO e' .. ao inves de ponto
                                      ;e start em minuscula
        cli                           ;para atendimento de interrupcao
                                      ;mascaravel para alterar registradores
                                      ;de segmento
        mov     ax,data
        mov     ds,ax
        mov     ax,stack
        mov     ss,ax
        mov     sp,stacktop
        sti                           ;volta a atender pino de INT
; ----- limpa a tela
        mov  ax,0003H
        int  10H
; ----- posiciona o cursor
;        mov  ah,2                    ;se fizer assim vai ter que posicionar
;        mov  dh,4                    ;o cursor a cada linha, e imprimir
;        mov  dl,14                   ;uma linha de cada vez. Veja como
;        mov  bh,0                    ;posicionei o cursor com "truques"
;        int  10H                     ;no texto do menu na area de dados.
; ----- escreve mensagem
        lea  dx,[msg1]
        mov  ah,9
        int  21H
; ----- le um caracter sem eco
le:     mov     ah,8
        int     21H
; ----- faz consistencia do caracter lido (testa se esta' entre 1 e 5)
        cmp     al, '1'
        jb      le
        cmp     al, '6'
        jnc     le
; ----- mostra caracter lido sem eco
        mov     ah,2
        mov     dl,al
        int     21H
; ----- termina o programa e volta o controle para o DOS
Done:   mov  ah,4ch          ;DOS terminate program function #
        int  21h             ;terminate the program
;
; Cria o segmento de dados
        segment data         ;apos esta pseudo-instrucao declare suas 
                             ;constantes
msg1:   db      13,10,10,10,10,'                   '  ; linha 5 coluna 20
        db      'Cadastro de alunos',13,10,10
        db      '         1 - Incluir',13,10
        db      '         2 - Excluir',13,10
        db      '         3 - Alterar',13,10
        db      '         4 - Consultar',13,10
        db      '         5 - Sair',13,10,10
        db      '         Opcao: $'
; Cria o segmento de pilha, e reserva espaco para uma pilha de 256 bytes
        segment stack stack        
        resb    256
stacktop:
        END



