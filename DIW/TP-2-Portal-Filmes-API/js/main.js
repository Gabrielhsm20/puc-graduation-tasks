var api_key = '',
    picture_path = 'http://image.tmdb.org/t/p/w185'

var destaques = {
  page: 0,
  elements: 0,
  results: []
};

var templateFilme = (el) => {
  return `
    <li class="col-sm-12 col-md-6 col-lg-6">
        <div class="card" style="background-image: url('${picture_path + el.poster_path}')">
        <div class="card-body">  
            <h4 class="card-title">
              <a href="https://www.google.com/search?q=${el.title}" target="_blank">${el.title}</a>
            </h4>
            <p class="card-text">Avaliação média: ${el.vote_average}</p>
            <p class="card-text">Descrição: ${el.overview.substring(0,300)}...</p>
          </div>
        </div>
    </li>
  `;
}

function buscaDestaques() {
  if(destaques.elements % 20 != 0) {
    appendDestaques(destaques.elements);
  } else {
    destaques.page++;

    fetch(`https://api.themoviedb.org/3/movie/popular?api_key=${api_key}&language=pt-BR&page=${destaques.page}`)
      .then(resp => resp.json())
      .then(data => {
        if(data.total_results) {
          destaques.results.push(...data.results);
          appendDestaques(destaques.elements);
        }
      });
   }
}

function appendDestaques(position) {
  destaques.results.slice(position, position + 4).forEach((el) => {
    $('section.destaques ul.row').append(templateFilme(el));
  });
  destaques.elements += 4;
}

$('#search').submit(function() {
  let query = $(this).find('input').val();

  fetch(`https://api.themoviedb.org/3/search/movie?api_key=${api_key}&language=pt-BR&page=1&include_adult=false&query=${query}`)
    .then(resp => resp.json())
    .then(data => {
      if(data.total_results) {
          $('section.destaques ul.row').html('');
          data.results.forEach((el) => {
            $('section.destaques ul.row').append(templateFilme(el));
          });
        } else {
          $('section.destaques ul.row').html(`
            <div class="col-12">
              <div class="alert alert-dark" role="alert">
                Nenhum filme encontrado
              </div>
            </div>
          `);
        }
    });

  return false;
})