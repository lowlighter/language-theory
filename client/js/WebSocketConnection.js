var graphId = 0;

function WebSocketConnection(url) {
    if ("WebSocket" in window) {

        var ws = new WebSocket(url);
        var self = this;

        ws.onopen = function () {
            console.log("Opening a connection...");
            window.identified = false;
        };
        ws.onclose = function (evt) {
            console.log("I'm sorry. Bye!");
        };

        // Message du serveur
        ws.onmessage = function (evt) {
            var data = JSON.parse(evt.data);

            console.log('Message du serveur:');
            console.log(data);

            // Si c'est une erreur
            if(data.error) {
                appendTextInTerminal('<span class="terminal_resp terminal_error">' + data.error + '</span>');

            // Si c'est un tableau
            } else if (data.table) {

                var str_table = '<table class="table">';
                str_table += '<tr><th> x </th><th> y </th></tr>';
                for (var i = 0; i < data.x[0].length; i++) {
                    str_table += '<tr><td>' + Math.round(data.x[0][i]*100)/100 +'</td><td>' + Math.round(data.y[0][i]*100)/100 +'</td></tr>';
                }
                str_table += "</table>";
                appendTextInTerminal(str_table);

            // Si c'est un graph
            } else if(data.graph) {
                    appendChartInTerminal(data);

            // Si c'est une update de graph
            //} else if() {

                //chart.data = [{x: [1,2,3,4], y: [4,3,2,1], mode: 'lines'}]
                //chart.layout.showlegend = false;
                //Plotly.redraw(chart);

            // Si c'est une autre réponse 
            } else {
                if(data.result != null) appendTextInTerminal(highlighterLight('<span class="terminal_resp">' + data.result + '</span>', grammar));
            }
        };
        ws.onerror = function (evt) {
            console.log("ERR: " + evt.data);
        };

        this.write = function () {
            if (window.identified) {
                connection.ident();
                console.debug("Wasn't identified earlier. It is now.");
            }
            this.send(theText.value);
        };

        this.ident = function () {
            var session = "Test";
            this.send(session, function () {
                window.identified = true;
                theText.value = "Hello!";
                say.click();
                theText.disabled = false;
            });
        };

        this.send = function (message, callback) {
            this.waitForConnection(function () {
                ws.send(message);
                if (typeof callback !== 'undefined') {
                  callback();
                }
            }, 1000);
        };

        this.waitForConnection = function (callback, interval) {
            if (ws.readyState === 1) {
                callback();
            } else {
                var that = this;
                // optional: implement backoff for interval here
                setTimeout(function () {
                    that.waitForConnection(callback, interval);
                }, interval);
            }
        };
    } else {
        console.log("Your browser doesn't support WebSocket.");
    }
}
