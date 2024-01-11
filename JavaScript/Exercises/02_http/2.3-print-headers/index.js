const http = require('http');

const server = http.createServer();
server.on('request', (request, response) => {
    response.writeHead(200, { 'Content-Type': 'text/html' });
    response.write(JSON.stringify(request.headers));
    response.end();
});

server.listen(3000);