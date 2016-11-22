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
                labels: ["Red", "Blue", "Yellow", "Green", "Purple", "Orange"],
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

