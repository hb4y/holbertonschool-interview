#!/usr/bin/node

/*
Script that prints all characters of a Star Wars movie:

The first positional argument passed is the Movie ID - example: 3 = “Return of the Jedi”
Display one character name per line in the same order as the “characters” list in the /films/ endpoint
*/

const URL = 'https://swapi-api.hbtn.io/api/';
const request = require('request');
const movieId = process.argv[2];

async function getRequest (url) {
  return new Promise(function (resolve, reject) {
    request.get(url, function (err, resp, body) {
      if (err) {
        reject(err);
      } else {
        resolve(JSON.parse(body));
      }
    });
  });
}

(async () => {
  return getRequest(URL + 'films/' + movieId);
})().then(async (movie) => {
  if (movie.detail !== 'Not found') {
    for (const ch of movie.characters) {
      const charc = await getRequest(ch);
      if (charc.detail === undefined) {
        console.log(charc.name);
      }
    }
  }
});
