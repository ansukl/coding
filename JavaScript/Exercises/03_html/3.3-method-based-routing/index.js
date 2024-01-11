const http = require('http');
const fs = require('fs');
const path = require('path');

http.createServer(function (req, res) {
    const method = req.method;
    if (method === 'GET') {
        readFileSendResponse('get.html', 'text/html', res);
    } else if (method === 'POST') {
        readFileSendResponse('post.html', 'text/html', res);
    } else {
      //res.statusCode = 405;
      res.writeHead(405, { 'Allow': "GET, POST" });
      res.statusMessage = 'Method Not Allowed';
      res.end();
    }
}).listen(3000);

/* 
  * @param {string} fileName - name of the file to be read
  * @param {string} contentType - type of the content to be sent in the response
  * @param {object} response - response object
  */
const readFileSendResponse = (fileName, contentType, response) => {
    fs.readFile(path.resolve(fileName), function (error, file) {
      if (error) {
        response.writeHead(404);
        response.write('Requested content not found');
      } else {
        response.writeHead(200, { 'Content-Type': contentType });
        response.write(file);
      }
      response.end();
    })
  }