const form = document.getElementById("form");
const contacts = document.getElementById("contacts");
const template = document.getElementById("contact-template");

form.addEventListener("submit", function (event) {
    event.preventDefault();
    const formData = new FormData(form);
    const clone = template.content.cloneNode(true);
    clone.querySelector("h2").textContent = formData.get("name");
    clone.querySelector("p.email").textContent = formData.get("email");
    clone.querySelector("a").href = formData.get("homepage");
    clone.querySelector("a").textContent = formData.get("homepage");
    contacts.appendChild(clone);
    form.reset();
  });