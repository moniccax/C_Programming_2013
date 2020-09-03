; 2 Aula Pratica de Microprocessadores
;
; Objetivos: 
; 1 - Exercitar os conhecimentos aprendidos na aula anterior com o programa  
;     aula1.asm. 
;
; 2 - Desenvolver um grupo de rotinas para facilitar a programacao assembly:
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
        org     0100H                 ;pseudo instrucao obrigatoria para
                                      ;um programa .COM onde 0100H e' o
                                      ;load address (endereco de carga do
                                      ;programa na memoria
        section .text                 ;apos esta pseudo instrucao coloque
                                      ;o codigo do seu programa
START:                                ;aqui inicia a execucao do programa
                                      ;este e' o entry point ou start address
;






; termina o programa e volta o controle para o DOS
Done:   mov  ah,4ch          ;DOS terminate program function #
        int  21h             ;terminate the program
;        
        section .data        ;apos esta pseudo-instrucao declare suas 
                             ;constantes
;


;
        section .bss         ;apos esta pseudo-instrucao declare suas 
                             ;variaveis

;
        END



