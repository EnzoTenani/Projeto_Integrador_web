var playerElement = document.getElementById('player');

// Definindo o Module antes de carregar o game.js
var Module = {
  onRuntimeInitialized: function() {
    console.log('WebAssembly carregado com sucesso!');

    // Usamos cwrap para criar funções JavaScript que chamam as funções C
    var movePlayer = Module.cwrap('move_player', null, ['number']);
    var getPlayerX = Module.cwrap('get_player_x', 'number', []);
    var getPlayerY = Module.cwrap('get_player_y', 'number', []);

    console.log('Funções WebAssembly configuradas:', movePlayer, getPlayerX, getPlayerY);

    // Atualiza a posição do jogador na tela
    function updatePlayerPosition() {
      var x = getPlayerX() || 5;
      var y = getPlayerY() || 5;
      console.log('Posição do jogador:', x, y);
      playerElement.style.left = (x * 20) + 'px';
      playerElement.style.top = (y * 20) + 'px';
    }

    // Eventos de teclado para mover o jogador
    document.addEventListener('keydown', function(event) {
      if (event.key === 'ArrowUp') {
        console.log('Tecla Cima pressionada');
        movePlayer(0);  // Cima
      } else if (event.key === 'ArrowDown') {
        console.log('Tecla Baixo pressionada');
        movePlayer(1);  // Baixo
      } else if (event.key === 'ArrowLeft') {
        console.log('Tecla Esquerda pressionada');
        movePlayer(2);  // Esquerda
      } else if (event.key === 'ArrowRight') {
        console.log('Tecla Direita pressionada');
        movePlayer(3);  // Direita
      } else {
        return; // Ignora outras teclas
      }
      updatePlayerPosition();
      event.preventDefault(); // Evita a rolagem da página
    });

    // Inicializa a posição do jogador
    updatePlayerPosition();
  }
};

