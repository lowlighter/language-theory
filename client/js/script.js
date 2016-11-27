var input = document.querySelector('#input');
var terminal = document.querySelector('#terminal');

test = new WebSocketConnection("ws://localhost:8080/echo");


var grammar = [{
				rule: /[\+\-\*\/=\^]/gi,
				color: "#FFCCFF"
			},{
				rule: /(cos|sin|plot)/gi,
				color: "#FFFFCC"
			},{
				rule: /[\(\)]/gi,
				color: "#CCFFFF"
			}];

input.addEventListener('keyup', function(e) {
	highlighter('#input', grammar);
	switch (e.key) {
		case "Enter":
			if(input.value == "clear") {
				clearTerminal();
				input.value = "";
				break;
			}
			test.send(strip(input.innerHTML));
		    appendTextInTerminal(highlighterLight('>>> ' + input.innerHTML, grammar));
		    input.innerHTML = "";
			break;
		case "(":
			var savedSel = saveSelection(input);
			var position = savedSel.start;
			input.innerHTML = strip(input.innerHTML);
			input.innerHTML = [input.innerHTML.slice(0, position), ")", input.innerHTML.slice(position)].join('');
		    restoreSelection(input, savedSel);
		    highlighter('#input', grammar);
			break;
	}
});







