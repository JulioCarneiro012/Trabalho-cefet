# Trabalho-cefet

<p>&nbsp;</p>
<h1>Projeto de indicador de troca de oleo</h1>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp;<img src="https://www.google.com.br/search?hl=pt-BR&amp;authuser=0&amp;tbm=isch&amp;source=hp&amp;biw=1366&amp;bih=657&amp;ei=crI_XdeJO6y15OUPwrCl4Ag&amp;q=luz+de+oleo+no+painel&amp;oq=luz+de+oleo&amp;gs_l=img.3.0.35i39j0l9.1308.3378..3955...0.0..0.244.2057.2j10j3......0....1..gws-wiz-img.....0.E5loFUXVn-w#imgrc=BaqCJFWENGXnbM:" alt="" width="100" height="150" /></p>
<p>&nbsp;</p>
<p>Sum&aacute;rio</p>
<p>Pag 3.............................................................Componentes do projeto</p>
<p>Pag 4.............................................................Programa</p>
<p>Pag 5.............................................................Vantagens do projeto</p>
<p>Pag 6.............................................................Considera&ccedil;&otilde;es finais</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>Componentes</p>
<p>Este projeto do Ardu&iacute;no Uno &eacute; feito para indicar ao motorista quando trocar o &oacute;leo do carro por meio de um contador programado com a media de quilometros que &eacute; necess&aacute;ria a manuten&ccedil;&atilde;o da troca de oleo</p>
<p>&nbsp;A lista de material desse circuito fica assim :</p>
<ul>
<li>3 resistores de 1 K (um para cada d&iacute;gito/anodo)</li>
<li>1 resistor de 220 ohms (led IR do sensor &oacute;ptico)</li>
<li>1 resistor de 10 K (ligado ao sensor &oacute;ptico - receptor)</li>
<li>1 resistor de 10 K (pull up do bot&atilde;o de reset)</li>
<li>Display 7 segmentos de 3 d&iacute;gitos CPS03631BR</li>
<li>Sensor &oacute;ptico reflexivo TCRT5000</li>
<li>1 push-button</li>
<li>1 Ardu&iacute;no Genu&iacute;no Uno</li>
</ul>
<p><br /> </p>
<p>&nbsp;</p>
<p><em>&nbsp;</em></p>
<p><img src="http://4.bp.blogspot.com/-1AycO6WOj7U/VL6lp0lOQGI/AAAAAAAADVY/lTB1RPZHutw/s1600/Contador-display-7-segmentos-botao-reset.png" /></p>
<p><em>&nbsp;</em></p>
<p><em>&nbsp;</em></p>
<p style="text-align: center;"><em>Programa</em></p>

<p><em>// Programa : Contador utilizando display 7 segmentos,</em></p>
<p><em>// Autor : Arduino e Cia&nbsp; </em></p>
<p>&nbsp;</p>
<p><em>// Carrega a biblioteca SevSeg</em></p>
<p>#include "SevSeg.h"&nbsp;&nbsp;</p>
<p>&nbsp;</p>
<p>SevSeg sevseg;&nbsp;</p>
<p>&nbsp;</p>
<p><em>// Cria variaveis globais&nbsp; </em></p>
<p><strong>int</strong> contador = 0;&nbsp;</p>
<p>&nbsp;</p>
<p><em>// Ligado ao pino "coletor" do sensor &oacute;ptico - Porta A5 ao Arduino&nbsp; </em></p>
<p><strong>int</strong> pinosensor = 19;</p>
<p><em>// Pino ligado ao botao de reset</em></p>
<p><strong>int</strong> pino_botao_reset = A0;</p>
<p><em>// Armazena o valor lido pelo sensor optico</em></p>
<p><strong>int</strong> leitura;</p>
<p><em>// Armazena o estado do botao reset</em></p>
<p><strong>int</strong> estadobotao = 0;</p>
<p>&nbsp;</p>
<p><strong>void</strong> setup()</p>
<p>{&nbsp;</p>
<p>&nbsp; <em>// Utilizando display de anodo comum, </em></p>
<p>&nbsp; <em>// pinos dos digitos : 10 a 13&nbsp; </em></p>
<p>&nbsp; <em>// Pino dos segmentos : 2 a 9&nbsp; </em></p>
<p>&nbsp; sevseg.Begin(1,13,10,11,12,2,3,4,5,6,7,8,9);&nbsp;</p>
<p>&nbsp; <em>// Controla a luminosidade - 0 a 100&nbsp; </em></p>
<p>&nbsp; sevseg.Brightness(20);&nbsp;</p>
<p>&nbsp; <em>// Define o pino do sensor optico como entrada </em></p>
<p>&nbsp; pinMode(pinosensor, INPUT);&nbsp;</p>
<p>&nbsp; <em>// Define o pino do botao reset como entrada</em></p>
<p>&nbsp; pinMode(pino_botao_reset, INPUT);</p>
<p>}&nbsp;</p>
<p>&nbsp;&nbsp;</p>
<p><strong>void</strong> loop()</p>
<p>{&nbsp;</p>
<p>&nbsp; sevseg.PrintOutput();&nbsp;</p>
<p>&nbsp; sevseg.NewNum(contador,(byte) 2);</p>
<p>&nbsp;</p>
<p>&nbsp; <em>// Verifica se o botao reset foi pressionado</em></p>
<p>&nbsp; estadobotao = digitalRead(pino_botao_reset);</p>
<p>&nbsp; <strong>if</strong> (estadobotao != 1)</p>
<p>&nbsp; {</p>
<p>&nbsp;&nbsp;&nbsp; <em>// Zera o contador</em></p>
<p>&nbsp;&nbsp;&nbsp; contador = 0;</p>
<p>&nbsp; }</p>
<p>&nbsp;</p>
<p>&nbsp; <em>// Le as informa&ccedil;&otilde;es do pino do sensor optico</em></p>
<p>&nbsp; leitura = digitalRead(pinosensor);</p>
<p>&nbsp; <em>// Verifica se o objeto foi detectado pelo sensor</em></p>
<p>&nbsp; <strong>if</strong> (leitura != 1)</p>
<p>&nbsp; {&nbsp;</p>
<p>&nbsp;&nbsp;&nbsp; <em>// Incrementa o valor do contador</em></p>
<p>&nbsp;&nbsp;&nbsp; contador = contador++;&nbsp;&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;&nbsp;&nbsp; <em>// Loop caso o objeto pare sobre o sensor </em></p>
<p>&nbsp;&nbsp;&nbsp; <strong>while</strong>(digitalRead(pinosensor) != 1)&nbsp;</p>
<p>&nbsp;&nbsp;&nbsp; {&nbsp;</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp; sevseg.PrintOutput();&nbsp;</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp; sevseg.NewNum(contador,(byte) 2);&nbsp;</p>
<p>&nbsp;&nbsp;&nbsp; }&nbsp;</p>
<p>&nbsp; }&nbsp;&nbsp;</p>
<p>}</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>A troca de &oacute;leo do carro &eacute; feita de 5,000 km em 5,000 km sendo assim quando o hodometro do carro chega perto de 4,800 km a luz do painel acende indicando ao motorista que &eacute; necess&aacute;rio uma troca de &oacute;leo</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p><img src="https://i.vrum.com.br/KmAttjsQDI4XhVs7ZWo541ifFP4=/675x/smart/imgsapp.estadodeminas.vrum.com.br/app/noticia_128576568202/2011/09/21/44535/20110921175647477943a.jpg" /></p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>Ap&oacute;s a troca de &oacute;leo basta o motorista acionar o bot&atilde;o situado ao lado do volante do carro para reiniciar o contador e repetir o processo</p>
<p>Vantagens da troca de &oacute;leo</p>
<p>A lubrifica&ccedil;&atilde;o correta &eacute; fundamental para a vida &uacute;til do motor e deve fazer parte da rotina de manuten&ccedil;&atilde;o do ve&iacute;culo. A fun&ccedil;&atilde;o b&aacute;sica do &oacute;leo &eacute;, que com sua viscosidade, se evite atrito entre as pe&ccedil;as do motor, impedindo que se desgastem ou at&eacute; travem o motor. Por essa raz&atilde;o, a troca deve ser feita regularmente, pois o &oacute;leo vai aos poucos perdendo sua viscosidade e ader&ecirc;ncia.</p>
<p>E com o contador o condutor do autom&oacute;vel ser&aacute; avisado sempre que o &oacute;leo do seu carro deve ser trocado prolongando assim a vida do motor</p>
<p>Considera&ccedil;&otilde;es finais</p>
<p>Autor do projeto:J&uacute;lio Carneiro</p>
<p>Docente: Epaminondas Lage</p>
<p>Programa do contador: Ardu&iacute;no e cia</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
