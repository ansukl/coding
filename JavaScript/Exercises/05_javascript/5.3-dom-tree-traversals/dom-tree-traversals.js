function countLi(node) {
    const counter = node.getElementsByTagName('li').length;

    if (counter != 0) {
        node.childNodes.item(0).data += `(${counter})`;
    }
}

const lists = document.querySelectorAll('li');
lists.forEach(countLi);


