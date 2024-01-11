const responseUtils = require('./utils/responseUtils');
const { acceptsJson, isJson, parseBodyJson } = require('./utils/requestUtils');
const { renderPublic } = require('./utils/render');
const { emailInUse, getAllUsers, saveNewUser, validateUser, updateUserRole, getUserById, deleteUserById } = require('./utils/users');
const { getCurrentUser } = require('./auth/auth');


const data = {
  // Make copies of products (prevents changing from outside this module/file)
  products: require("./products.json").map(product => ({...product })),
};

/**
 * Known API routes and their allowed methods
 *
 * Used to check allowed methods and also to send correct header value
 * in response to an OPTIONS request by sendOptions() (Access-Control-Allow-Methods)
 */
const allowedMethods = {
  '/api/register': ['POST'],
  '/api/users': ['GET'],
  "/api/products": ["GET"]
};

/**
 * Send response to client options request.
 *
 * @param {string} filePath pathname of the request URL
 * @param {http.ServerResponse} response
 */
const sendOptions = (filePath, response) => {
  if (filePath in allowedMethods) {
    response.writeHead(204, {
      'Access-Control-Allow-Methods': allowedMethods[filePath].join(','),
      'Access-Control-Allow-Headers': 'Content-Type,Accept',
      'Access-Control-Max-Age': '86400',
      'Access-Control-Expose-Headers': 'Content-Type,Accept'
    });
    return response.end();
  }

  return responseUtils.notFound(response);
};

/**
 * Does the url have an ID component as its last part? (e.g. /api/users/dsf7844e)
 *
 * @param {string} url filePath
 * @param {string} prefix
 * @returns {boolean}
 */
const matchIdRoute = (url, prefix) => {
  const idPattern = '[0-9a-z]{8,24}';
  const regex = new RegExp(`^(/api)?/${prefix}/${idPattern}$`);
  return regex.test(url);
};

/**
 * Does the URL match /api/users/{id}
 *
 * @param {string} url filePath
 * @returns {boolean}
 */
const matchUserId = url => {
  return matchIdRoute(url, 'users');
};

const handleRequest = async(request, response) => {
  const { url, method, headers } = request;
  const filePath = new URL(url, `http://${headers.host}`).pathname;

  // serve static files from public/ and return immediately
  if (method.toUpperCase() === 'GET' && !filePath.startsWith('/api')) {
    const fileName = filePath === '/' || filePath === '' ? 'index.html' : filePath;
    return renderPublic(fileName, response);
  }

  if (matchUserId(filePath)) {
    // TODO: 8.6 Implement view, update and delete a single user by ID (GET, PUT, DELETE)
    // You can use parseBodyJson(request) from utils/requestUtils.js to parse request body
    // If the HTTP method of a request is OPTIONS you can use sendOptions(filePath, response) function from this module
    // If there is no currently logged in user, you can use basicAuthChallenge(response) from /utils/responseUtils.js to ask for credentials
    //  If the current user's role is not admin you can use forbidden(response) from /utils/responseUtils.js to send a reply
    // Useful methods here include:
    // - getUserById(userId) from /utils/users.js
    // - notFound(response) from  /utils/responseUtils.js 
    // - sendJson(response,  payload)  from  /utils/responseUtils.js can be used to send the requested data in JSON format

    // Split /api/users/ta84ub0bp -> ["api", "users", "ta84ub0bp"] and take last item
    const userId = filePath.split("/").pop();

    const user = await getCurrentUser(request);
    if (user === null) {
      return responseUtils.basicAuthChallenge(response);
    } else if (user.role !== "admin") {
      return responseUtils.forbidden(response);
    }

    if (method === "GET") {
      const targetUser = getUserById(userId);
      return (targetUser ? responseUtils.sendJson(response, targetUser) : responseUtils.notFound(response)); 
    } 
    
    else if (method === "PUT") {
      let body = null;
      try {
        body = await parseBodyJson(request);
      } catch (err) {
        return responseUtils.badRequest(response, 'Bad Request');
      }

      if (!("role" in body)) {
        // Role not found
        return responseUtils.badRequest(response, "Role missing");
      } else if (!body["role"]) {
        // Role is present but empty
        return responseUtils.badRequest(response, "Role empty");
      } else if (body["role"] !== "admin" && body["role"] !== "customer") {
        // Role is not admin or customer
        return responseUtils.badRequest(response, "Invalid role");
      }

      const updatedUser = updateUserRole(userId, body.role)
      return (updatedUser ? responseUtils.sendJson(response, updatedUser) : responseUtils.notFound(response)); 
    } 
    
    else if (method === "DELETE") {
      const deletedUser = deleteUserById(userId);
      return (deletedUser ? responseUtils.sendJson(response, deletedUser) : responseUtils.notFound(response)); 
    } 
    
    else if (method === "OPTIONS") {
      sendOptions(filePath, response);
    } 
    
    else {
      return responseUtils.methodNotAllowed(response);
    }
  }

  // Default to 404 Not Found if unknown url
  if (!(filePath in allowedMethods)) return responseUtils.notFound(response);

  // See: http://restcookbook.com/HTTP%20Methods/options/
  if (method.toUpperCase() === 'OPTIONS') return sendOptions(filePath, response);

  // Check for allowable methods
  if (!allowedMethods[filePath].includes(method.toUpperCase())) {
    return responseUtils.methodNotAllowed(response);
  }

  // Require a correct accept header (require 'application/json' or '*/*')
  if (!acceptsJson(request)) {
    return responseUtils.contentTypeNotAcceptable(response);
  }

  // GET all users
  if (filePath === '/api/users' && method.toUpperCase() === 'GET') {
    // TODO: 8.5 Add authentication (only allowed to users with role "admin")
    const user = await getCurrentUser(request);

    if (user === null) {
      return responseUtils.basicAuthChallenge(response);
    } else {
      if (user.role === "admin") {
        return responseUtils.sendJson(response, getAllUsers());
      } else {
        return responseUtils.forbidden(response);
      }
    }
  }

  // register new user
  if (filePath === '/api/register' && method.toUpperCase() === 'POST') {
    // Fail if not a JSON request, don't allow non-JSON Content-Type
    if (!isJson(request)) {
      return responseUtils.badRequest(response, 'Invalid Content-Type. Expected application/json');
    }

    // TODO: 8.4 Implement registration
    // You can use parseBodyJson(request) method from utils/requestUtils.js to parse request body.
    // Useful methods here include:
    // - validateUser(user) from /utils/users.js 
    // - emailInUse(user.email) from /utils/users.js
    // - badRequest(response, message) from /utils/responseUtils.js
    try {
      const user = await parseBodyJson(request);
      if (validateUser(user).length !== 0) {
        return responseUtils.badRequest(response, 'Bad Request');
      }

      if (emailInUse(user.email)) {
        return responseUtils.badRequest(response, 'Bad Request');
      }

      const createdUser = saveNewUser(user);
      const modified = updateUserRole(createdUser._id, "customer");
      return responseUtils.createdResource(response, modified);

    } catch (err) {
      return responseUtils.badRequest(response, 'Bad Request');
    }
  }

  if (filePath === "/api/products" && method.toUpperCase() === "GET") {
    const user = await getCurrentUser(request);

    if (user === null) {
      return responseUtils.basicAuthChallenge(response);
    } else {
      return responseUtils.sendJson(response, data.products);
    }
  }
};

module.exports = { handleRequest };