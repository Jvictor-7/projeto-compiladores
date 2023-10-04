# projeto-compiladores
Projeto e Gramática  “Desenvolver um Interpretador de Sessões On-Line” (Analisadores Léxico e Sintático e Execução do programa)  segundo a Gramática proposta
# Como rodar o projeto
Para conseguir rodar o projeto é preciso ter instalado o mingw. Clone o repositório e vá até a pasta destino pelo terminal de seu sistema operacional. No  windows, rode o comando mingw32-make , e depois basta abrir o arquivo teste. Por hora o programa so funciona somente no windows, uma vez que estamos utilizando bibliotecas do windows para emitir alertas conforme o tempo . O arquivo de entrada se chama input.txt, e é nele que você deve escrever os terminais da gramática. Também é possível ignorar linhas ao digitar // . Instruções sobre a gramática podem ser encontradas na pasta grammar. Também existem códigos de exemplo na pasta code_examples
=======
# Projeto e Gramática - Interpretador de Sessões On-Line

> Neste projeto, basicamente foi desenvolvido na linguagem C: Analisadores Léxico, Sintático e a Execução do programa conforme a Gramática proposta.
> OBS: As instruções da gramática podem ser encontradas na pasta grammar. Também existem códigos de exemplo na pasta code_examples.

## 💻 Pré-requisitos

Antes de começar, verifique se você atendeu aos seguintes requisitos:

* Você instalou a versão mais recente do **[MinGW](https://sourceforge.net/projects/mingw/)**
* Você tem uma máquina `<Windows>`. Infelizmente o programa só é compatível com o Windows, pois foi utilizado bibliotecas do Windows para emitir alertas conforme o tempo.
* Você leu a **[Gramática](https://github.com/Jvictor-7/projeto-compiladores/blob/main/grammar/Gramatica-BNF-Projeto-Interpretador-Atualizado.pdf)**.

## 🚀 Como rodar o projeto

Para que o projeto funcione corretamente, siga estas etapas:

Windows:
```
- Instalar o MinGW (necessário para compilar o código C no windows e rodar o arquivo Makefile)
- Clonar o repositório
- Acesse o diretório pelo terminal onde o repositório foi clonado
- Execute o comando mingw32-make
- Abra o arquivo teste, nele você deve escrever os terminais da gramática (o interpretador suporta comentarios utilizando //)
- Rode no terminal o comando ./teste
```

## 🤝 Colaboradores

Agradecemos às seguintes pessoas que contribuíram para este projeto:

<table>
  <tr>
    <td align="center">
      <a>
        <img src="https://avatars.githubusercontent.com/u/81593768?v=4" width="100px;" alt="Foto do Iuri Silva no GitHub"/><br>
        <sub>
          <b>João Victor Cavalcante Lima</b>
          <br>
          <a href="https://github.com/Jvictor-7">Github</a>
        </sub>
      </a>
    </td>
    <td align="center">
      <a>
        <img src="https://avatars.githubusercontent.com/u/86822537?v=4" width="100px;" alt="Foto do Mark Zuckerberg"/><br>
        <sub>
          <b>José Fabiano Silva de Andrade</b>
          <br>
          <a href="https://github.com/Radbios">Github</a>
        </sub>
      </a>
    </td>
    <td align="center">
      <a>
        <img src="https://avatars.githubusercontent.com/u/91622210?v=4" width="100px;" alt="Foto do Steve Jobs"/><br>
        <sub>
          <b>Bruno Luiz Florentino Silva</b>
          <br>
          <a href="https://github.com/Brunot101">Github</a>
        </sub>
      </a>
    </td>
    <td align="center">
      <a>
        <img src="https://avatars.githubusercontent.com/u/106382466?v=4" width="100px;" alt="Foto do Steve Jobs"/><br>
        <sub>
          <b>Priscila Teodório Da Silva</b>
          <br>
          <a href="https://github.com/techpril">Github</a>
        </sub>
      </a>
    </td>
  </tr>
</table>
