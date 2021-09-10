#!/usr/bin/node

/*
Write a script that prints all
characters of Star Wars:
*/

const URL = 'https://swapi-api.hbtn.io/api/';
const r = require('request');
const mov = process.argv[2];

async function sw_get (url) {
  return new Promise(function (resolve, reject) {
    r.get(url, function (err, resp, body) {
      if (err) {
        reject(err);
      } else {
        resolve(JSON.parse(body));
      }
    });
  });
}
(async () => {
  return sw_get(URL + 'films/' + mov);
})().then(async (curr_movie) => {
  if (curr_movie.detail !== 'Not found') {
    for (const ch of curr_movie.characters) {
      const character = await sw_get(ch);
      if (character.detail === undefined) {
        console.log(character.name);
      }
    }
  }
});
