// axios.get('https://libretranslate.com/languages',
//      {headers:{'accept':'application/json'}})

const tgt =  document.querySelector('#list-from-languages');
+

fetch('https://libretranslate.com/languages',{headers:{'accept':'application/json'}})
    .then(res => {
        console.log(res,res.data)
    })

opt = document.createElement("option");
opt.value = "value";
opt.textContent = "text to be displayed";
tgt.appendChild(opt);