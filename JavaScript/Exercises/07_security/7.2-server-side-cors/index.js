const http = require('http');
const port = 3000;
const fs = require('fs');
const path = require('path');

http.createServer((req, res) => {

  /** TODO: add the required CORS headers 
   * as speciiied in the exercise instructions.
   * You can define your CORS header with something
   * like the following:
   * const headers = {
      'header_1_name': 'header_1_value',
      'header_2_name': 'header_2_value',
      ...
      };
      This syntax enables using the defined CORS headers with  writeHead() method in the TODOs below. See writeHead() method parameters: (https://nodejs.org/api/http.html#http_response_writehead_statuscode_statusmessage_headers).
  */
  const headers = {
    "Access-Control-Allow-Origin": "*",
    "Access-Control-Allow-Methods": "POST, GET, HEAD",
    "Access-Control-Max-Age": 14400
  };

  let filePath = path.join(__dirname, 'index.html');
  let stat = fs.statSync(filePath);

  // The three lines of code below, ending with 'res.end(data);',
  // are here to enable testing
  // the server and CORS headers, when you seek to remove
  // the CORS error shown in the browser DevTools.
  //
  //  IMPORTANT! DELETE THE THREE LINES BELOW ENDING WITH 'res.end(data);', 
  //  BUT only after you
  // have already defined a working set of CORS headers above. So,
  // remove the lines after you have completed the TODO above, but 
  // before you start to write your own code for the TODOs below.

  // TODO: check that Origin header is set in all incoming requests
  // You can access the header with req.headers['origin']
  // You can check if a header is present in request headers with if(!req.headers['yourHeaderNameHere']){..

  //console.log(req.headers);

  if(!req.headers['origin']){
    res.writeHead(400);
    res.write("Origin header not in the request");
    res.end();
    return;
  }


  const method = req.method;
  if (method === 'HEAD') {
    res.writeHead(200, headers);
    res.end();
  } else if (method === 'POST' || method === 'GET') {
    res.writeHead(200, headers);
    res.write("I was requested using CORS!");
    res.end();
  } else {
    res.writeHead(405, headers);
    res.write("Request used a HTTP method which is not allowed.");
    res.end();
  }





}).listen(port);