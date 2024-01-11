const ulClass = document.querySelector("ul.navi");
const ol = document.getElementById("ordered");
ulClass.classList.add("list");

const newLi = document.createElement('li');
const newA = document.createElement('a');
newA.href = 'http://localhost:3000/';
newA.text = 'Localhost';
newLi.appendChild(newA);
ulClass.appendChild(newLi);

const newLi2 = document.createElement('li');
const text = document.createTextNode('Item 0');
newLi2.appendChild(text);
ol.insertBefore(newLi2, ol.firstChild);

const ulTodo = document.getElementById("todo");
ulTodo.classList.remove("navi");

const children = ulTodo.children;
ulTodo.removeChild(children[1]);