var pai = window.opener;
function EnviarProPai(Texto){
	pai.document.getElementById('texto1').value = document.getElementById('primeironome').value;
    pai.document.getElementById('texto2').value = document.getElementById('ultimonome').value;
	pai.document.getElementById('texto3').value = document.getElementById('email').value;
	pai.document.getElementById('texto4').value = document.getElementById('dia').value;
	pai.document.getElementById('texto5').value = document.getElementById('mes').value;
    pai.document.getElementById('texto6').value = document.getElementById('ano').value;
	pai.document.getElementById('texto7').value = document.getElementById('sexo').value;
	pai.document.getElementById('div').innerHTML = 'Isto e um div com texto \"'+ document.getElementById('txt_div').value +'\"';
	
	window.close();

}

