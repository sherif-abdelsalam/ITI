import { DrawUi } from "./modules/drawUi.js";


fetch('https://jsonplaceholder.typicode.com/users')
      .then(res => res.json())
      .then(data => DrawUi(data));

