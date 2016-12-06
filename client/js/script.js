var input = document.querySelector('#input');
var terminal = document.querySelector('#terminal');

socketConnection = new WebSocketConnection("ws://localhost:8080/echo");

// Gestion de l'historique avec les flèches du clavier
var historyArr = [];
historyPtr = 0;


// Grammaire côté client pour la coloration syntaxique
var grammar = [{
				rule: /[\+\-\*\/=\^]/gi,
				color: "#FFCCFF"
			},{
				rule: /(cos|sin|plot|exp|acos|atan|asin|sinh|cosh|tanh|abs)/gi,
				color: "#FFFFCC"
			},{
				rule: /[\(\)]/gi,
				color: "#CCFFFF"
			}];




input.addEventListener('keyup', function(e) {

	// Coloration syntaxique de l'entrée de l'utilisateur
	highlighter('#input', grammar);

	switch (e.key) {
		// Appuie sur la touche entrer
		case "Enter":
			if(strip(input.innerHTML) == "clear") {
				clearTerminal();
				input.innerHTML = "";
				break;
			} else if(input.innerHTML == "<br>")
			{
				break;	
			}
			console.log(input.innerHTML)
			socketConnection.send(strip(input.innerHTML));
		    appendTextInTerminal(highlighterLight('>>> ' + input.innerHTML, grammar));
		    terminal.scrollTop = terminal.scrollHeight;
		    historyArr.push(input.innerHTML);
		    historyPtr = historyArr.length;
		    input.innerHTML = "";
			break;

		// Appuie sur la flèche du haut
		case "ArrowUp":
			if(historyPtr > 0) {
				historyPtr -- ;
				input.innerHTML = historyArr[historyPtr];
			}
			break;

		// Appuie sur la flèche du bas
		case "ArrowDown":
			if(historyPtr < historyArr.length-1) {
				historyPtr ++ ;
				input.innerHTML = historyArr[historyPtr];
			}
			break;
	}
});









