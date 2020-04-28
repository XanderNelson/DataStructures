// const http = require('http')
// const port = 3000
//
// const requestHandler = (request, response) => {
//   console.log(request.url)
//   response.end('Hello Node.js Server!')
//   // var fs = require("fs");
//   // var data = fs.readFileSync("Game.txt", "utf8");
//   //
//   // console.log(data);
// }
//
// const server = http.createServer(requestHandler)
//
// server.listen(port, (err) => {
//   if (err) {
//     return console.log('something bad happened', err)
//   }
//
//   console.log(`server is listening on ${port}`)
// })
//-----------------------------------------------------
var http = require('http');
var fs = require('fs');
var reload = require('reload')
const PORT=8080;

fs.readFile('./Game.txt', function (err, html) {
  //location.reload();
    if (err) throw err;

    http.createServer(function(request, response) {
        response.writeHeader(200, {"Content-Type": "text/html"});
        response.write(html);
        response.end();
    }).listen(PORT);
    reload();
});
//-----------------------------------------------------
