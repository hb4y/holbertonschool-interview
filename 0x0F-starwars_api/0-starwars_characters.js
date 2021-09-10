#!/usr/bin/node

/*
Write a script that prints all
characters of Star Wars:
*/

const URL = 'https://swapi-api.hbtn.io/api/';
const r = require('request');
const mov = process.argv[2];

async function swGet (url) {
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
  return swGet(URL + 'films/' + mov);
})().then(async (currMovie) => {
  if (currMovie.detail !== 'Not found') {
    for (const ch of currMovie.characters) {
      const character = await swGet(ch);
      if (character.detail === undefined) {
        console.log(character.name);
      }
    }
  }
});
