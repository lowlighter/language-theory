var input = document.querySelector('#input');
var terminal = document.querySelector('#terminal');

test = new WebSocketConnection("ws://localhost:8080/echo");

input.addEventListener('keyup', function(e) {
	switch (e.key) {
		case "Enter":
			if(input.value == "clear") {
				clearTerminal();
				input.value = "";
				break;
			}
			test.send(input.value);
		    appendTextInTerminal('>>> ' + input.value);
		    input.value = "";
			break;
		case "(":
			var position = input.selectionStart;
			input.value = [input.value.slice(0, position), ")", input.value.slice(position)].join('');
		    input.setSelectionRange(position, position);
			break;
	}
});


