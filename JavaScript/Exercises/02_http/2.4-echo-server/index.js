const http = require('http');

const server = http.createServer();
server.on('request', (req, res) => {
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    let body = [];
    req.on('data', (chunk) => {
        body.push(chunk);
    }).on('end', () => {
        body = Buffer.concat(body).toString().split("").reverse().join("");
        res.end(body);
      });
});

server.listen(3000);