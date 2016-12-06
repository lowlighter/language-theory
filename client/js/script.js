var input = document.querySelector('#input');
var terminal = document.querySelector('#terminal');

socketConnection = new WebSocketConnection("ws://localhost:8080/echo");

var historyArr = [];
historyPtr = 0;

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
				input.innerHTML = "";
				break;
			}
			socketConnection.send(strip(input.innerHTML));
		    appendTextInTerminal(highlighterLight('>>> ' + input.innerHTML, grammar));
		    terminal.scrollTop = terminal.scrollHeight;
		    historyArr.push(input.innerHTML);
		    historyPtr = historyArr.length;
		    input.innerHTML = "";
			break;
		case "ArrowUp":
			if(historyPtr > 0) {
				historyPtr -- ;
				input.innerHTML = historyArr[historyPtr];
			}
			break;
		case "ArrowDown":
			if(historyPtr < historyArr.length-1) {
				historyPtr ++ ;
				input.innerHTML = historyArr[historyPtr];
			}
			break;
	}
});









