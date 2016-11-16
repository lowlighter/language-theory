var input = document.querySelector('#input');
var terminal = document.querySelector('#terminal');

test = new WebSocketConnection("ws://localhost:8080/echo");

input.addEventListener('keypress', function(e) {
  if(e.key == "Enter") {
    test.send(input.value);
    addTerminal(input.value);
    input.value = "";
  }
})

function addTerminal(msg) {
  console.log(msg);
  terminal.innerText += '>  ' + msg + '\r\n';
}
