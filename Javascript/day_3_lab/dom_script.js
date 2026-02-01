var centerDiv = document.querySelector('.center');

var image = document.querySelector('img');
image.style.display = 'block';
image.style.marginLeft = 'auto';

var navList = document.querySelector('#nav');
navList.style.listStyleType = 'circle';
navList.style.margin = '0 auto';
navList.style.display = 'inline-block';


centerDiv.append(image);
centerDiv.append(navList);

var imageLeftCole = image.cloneNode(true);
imageLeftCole.style.marginLeft = '0';
imageLeftCole.style.marginRight = 'auto';
centerDiv.append(imageLeftCole);


