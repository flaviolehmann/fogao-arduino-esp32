<h1>Fogão Controlado Por Arduino e ESP32</h1>
Implementação de uma aplicação em arduino para controle remoto de um fogão.
Desenvolvido como trabalho final na disciplina de Tópicos Especiais em Programação com o professor Júlio Vendramini (2019-1), no Ifes Campus Colatina.

<h4>O Projeto:</h4>
Controlar um fogão remotamente com o auxílio de ferramentas de IoT. Utilizamos um Arduino como unidade central de processamento, onde acoplamos todos os sensores. Utilizamos um ESP32 para servir uma aplicação web, onde o usuário é capaz de controlar elementos como temperatura do fogão e tempo até as chamas se apagarem. O controle também é possível via um display LCD acoplado ao Arduino.

<h4>Ferramentas Utilizadas:</h4>
<ol>
  <li>Arduino Nano</li>
  <li>ESP32</li>
  <li>LCD Display (utilizamos a versão com shield)</li>
  <li>Sensor Analógico de Temperatura</li>
  <li>Relé</li>
  <li>Sensor de Chamas</li>
</ol>

<h4>Montagem:</h4>
<ol>
  <li>Acopla-se o Arduino ao fogão, e todos os demais componentes ao Arduino.</li>
  <li>Conecta-se o Relé em algum ponto do circuito que alimenta a faísca elétrica do fogão.</li>
  <li>Mantem-se a faísca elétrica do fogão sempre pressionada, de forma que agora seja controlada somente pelo Relé.</li>
  <li>Posiciona-se o sensor de chamas próximo à boca do fogão.</li>
  <li>Posiciona-se o sensor de temperatura próximo ao recipiente sobre a boca do fogão.</li>
  <li>Pronto! O fogão agora já pode ser controlado utilizando o DisplayLCD+shield ou através da aplicação web.</li>
</ol>

<h4>Arquivos:</h4>
Os arquivos que devem ser inseridos no arduino localizam-se na pasta 'ino'. O arquivo de controle do ESP32 está na pasta 'esp'.

<h4>Dúvidas?</h4>
Gostou do projeto mas ficou com alguma dúvida? Tem alguma crítica ou sugestão? Envie-nos um email! Responderemos o mais rápido possível.
