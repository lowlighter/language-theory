function strip(html)
{
   var tmp = document.createElement("DIV");
   tmp.innerHTML = html;
   return tmp.textContent||tmp.innerText;
}

function saveSelection(containerEl) {
    var charIndex = 0, start = 0, end = 0, foundStart = false, stop = {};
    var sel = rangy.getSelection(), range;

    function traverseTextNodes(node, range) {
        if (node.nodeType == 3) {
            if (!foundStart && node == range.startContainer) {
                start = charIndex + range.startOffset;
                foundStart = true;
            }
            if (foundStart && node == range.endContainer) {
                end = charIndex + range.endOffset;
                throw stop;
            }
            charIndex += node.length;
        } else {
            for (var i = 0, len = node.childNodes.length; i < len; ++i) {
                traverseTextNodes(node.childNodes[i], range);
            }
        }
    }
    
    if (sel.rangeCount) {
        try {
            traverseTextNodes(containerEl, sel.getRangeAt(0));
        } catch (ex) {
            if (ex != stop) {
                throw ex;
            }
        }
    }

    return {
        start: start,
        end: end
    };
}

function restoreSelection(containerEl, savedSel) {
    var charIndex = 0, range = rangy.createRange(), foundStart = false, stop = {};
    range.collapseToPoint(containerEl, 0);
    
    function traverseTextNodes(node) {
        if (node.nodeType == 3) {
            var nextCharIndex = charIndex + node.length;
            if (!foundStart && savedSel.start >= charIndex && savedSel.start <= nextCharIndex) {
                range.setStart(node, savedSel.start - charIndex);
                foundStart = true;
            }
            if (foundStart && savedSel.end >= charIndex && savedSel.end <= nextCharIndex) {
                range.setEnd(node, savedSel.end - charIndex);
                throw stop;
            }
            charIndex = nextCharIndex;
        } else {
            for (var i = 0, len = node.childNodes.length; i < len; ++i) {
                traverseTextNodes(node.childNodes[i]);
            }
        }
    }
    
    try {
        traverseTextNodes(containerEl);
    } catch (ex) {
        if (ex == stop) {
            rangy.getSelection().setSingleRange(range);
        } else {
            throw ex;
        }
    }
}


function appendTextInTerminal(msg) {
  	terminal.insertAdjacentHTML('beforeend', msg + '<br>');
 	terminal.scrollTop = terminal.scrollHeight;
}

function clearTerminal() {
  	terminal.innerHTML = "";
}


var appendChartInTerminal = (function () {
    var chartId = 0;
    return function () {
    	terminal.insertAdjacentHTML('beforeend', '<div class="graphContainer"><canvas id="chart' + chartId +'"></canvas></div><br>');
        terminal.scrollTop = terminal.scrollHeight;
        var ctx = document.querySelector('#chart' + chartId);
        var myChart = new Chart(ctx, {
            type: 'line',
            data: {
                labels: [1, 2, 3, 4, 5, 6],
                datasets: [{
                    label: '# of Votes',
                    data: [12, 19, 3, 5, 2, 3],
                    backgroundColor: [
                        'rgba(255, 99, 132, 0.2)',
                        'rgba(54, 162, 235, 0.2)',
                        'rgba(255, 206, 86, 0.2)',
                        'rgba(75, 192, 192, 0.2)',
                        'rgba(153, 102, 255, 0.2)',
                        'rgba(255, 159, 64, 0.2)'
                    ],
                    borderColor: [
                        'rgba(255,99,132,1)',
                        'rgba(54, 162, 235, 1)',
                        'rgba(255, 206, 86, 1)',
                        'rgba(75, 192, 192, 1)',
                        'rgba(153, 102, 255, 1)',
                        'rgba(255, 159, 64, 1)'
                    ],
                    borderWidth: 1
                }]
            },
            options: {
                responsive: true,
                maintainAspectRatio: false,
                elements: {
                    point: {
                        radius: 0,
                        hitRadius: 20
                    }
                },
                scales: {
                    yAxes: [{
                        ticks: {
                            beginAtZero:true
                        }
                    }]
                },
                legend: {
                    display: false,
                }
            }
        });
		return chartId += 1;
	}
})();


function highlighter(selector, grammar) {

    var replace  = [];

    var field = document.querySelector(selector);
    
        var savedSel = saveSelection(field);
        field.innerHTML = field.innerHTML.replace("<br>","||br||");  
        field.innerHTML = field.innerHTML.replace(/(<([^>]+)>)/ig,"");
        field.innerHTML = field.innerHTML.replace("||br||","<br>"); 

        grammar.forEach(function(elt) {
            field.innerHTML = field.innerHTML.replace(elt.rule, function(str) {
                    replace.push('<font color=' + elt.color + '>' + str +'</font>')
                    return '\\' + (replace.length - 1) + '$$';
            });
           
        });

        replace.forEach(function(elt, key) {
            field.innerHTML = field.innerHTML.replace("\\" + key + "$$", function(str) {
                    return elt;
            });
           
        });

        restoreSelection(field, savedSel);          

}

function highlighterLight(str, grammar) {

    var replace  = [];

    
        str = str.replace(/(<([^>]+)>)/ig,"");
        str = str.replace("||br||","<br>"); 

        grammar.forEach(function(elt) {
            str = str.replace(elt.rule, function(str) {
                    replace.push('<font color=' + elt.color + '>' + str +'</font>')
                    return '\\' + (replace.length - 1) + '$$';
            });
           
        });

        replace.forEach(function(elt, key) {
            str = str.replace("\\" + key + "$$", function(str) {
                    return elt;
            });
           
        });

        return str;
}


