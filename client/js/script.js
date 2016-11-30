var input = document.querySelector('#input');
var terminal = document.querySelector('#terminal');

test = new WebSocketConnection("ws://localhost:8080/echo");

var a;

var grammar = [{
				rule: /[\+\-\*\/=\^]/gi,
				color: "#FFCCFF"
			},{
				rule: /(cos|sin|plot|exp)/gi,
				color: "#FFFFCC"
			},{
				rule: /[\(\)]/gi,
				color: "#CCFFFF"
			}];

input.addEventListener('keyup', function(e) {
	highlighter('#input', grammar);
	switch (e.key) {
		case "Enter":
			
			if(strip(input.innerHTML) == "clear") {
				clearTerminal();
				input.value = "";
				break;
			}
			test.send(strip(input.innerHTML));
		    appendTextInTerminal(highlighterLight('>>> ' + input.innerHTML, grammar));
		    input.innerHTML = "";
			break;
	}
});








