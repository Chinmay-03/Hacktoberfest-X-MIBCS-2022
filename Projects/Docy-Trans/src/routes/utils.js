
import axios from 'axios';
// const PDFExtract = require('pdf.js-extract').PDFExtract;
import fontkit from '@pdf-lib/fontkit';
import fetch from 'node-fetch'
import {PDFExtract} from 'pdf.js-extract';
const pdfExtract = new PDFExtract();
const options = {}; /* see below */

import  { degrees, PDFDocument, rgb, StandardFonts, translate } from 'pdf-lib';
import {readFile,writeFile} from 'fs/promises';

export const work = async (source,fromLang,toLang) => {

// const source = '../mmm.pdf';

const allPagesData = await pdfExtract.extract(source, options)
  let pagess = allPagesData.pages[0].content;


const existingPdfBytes = await readFile(source);

// Load a PDFDocument from the existing PDF bytes
const pdfDoc = await PDFDocument.load(existingPdfBytes)

// const openSansUrls = {
//   partial:
//     'https://fonts.gstatic.com/s/opensans/v17/mem8YaGs126MiZpBA-UFVZ0e.ttf',
//   full:
//     'https://github.com/google/fonts/raw/master/apache/opensans/OpenSans-Regular.ttf',
// };

// Download the font
// const url = openSansUrls.full;
// const url = 'https://pdf-lib.js.org/assets/ubuntu/Ubuntu-R.ttf';
// console.log(`Downloading font from ${url}\n`);
// const openSansBytes = await fetch(url).then((res) => res.arrayBuffer());
const openSansBytes = await readFile('../Karma-Regular.ttf');

// Embed the Helvetica font
const helveticaFont = await pdfDoc.embedFont(StandardFonts.Helvetica)
pdfDoc.registerFontkit(fontkit);
  const openSansFont = await pdfDoc.embedFont(openSansBytes);

// Get the first page of the document
const pages = pdfDoc.getPages()
const firstPage = pages[0]

// Get the width and height of the first page
const { width, height } = firstPage.getSize()

pagess.forEach(text => {
firstPage.drawRectangle({x: text.x,
  color: rgb(1, 1, 1),
  y: height - text.y - text.height,
  width: text.width,
  height: 75});
});


console.log(pagess.length);



function delay(n){
  return new Promise(function(resolve){
      setTimeout(resolve,n*1000);
  });
}

const fetchPromises =async ()=>{
  let result = [];
  let i, chunk;
for (i = 0; i < pagess.length; i += 39) {
    chunk = pagess.slice(i, i + 39);
    
result.push(...chunk.map(
  (text) =>{
    console.log(text)
    console.log("len:",chunk.length,"from ",i);
    return axios({url:'https://libretranslate.de/translate',
    method: 'post',
    data:{
      q: text.str,
      source: fromLang,
      target: toLang,
      format: "text"
    },
    headers:{
      // "accept":"application/json",
      "Content-Type":"application/json",
    },
  })
}))
 if(pagess.length >35){
  console.log("Waiting for 60 s");
  await delay(60);
}
}
return result;
}



const translatedTexts = await Promise.all(
  await fetchPromises()
  )
    ;

translatedTexts.forEach(x=>console.log(x.data.translatedText))

for(const textNo in translatedTexts){

  console.log(translatedTexts[textNo].data.translatedText)
firstPage.drawText(translatedTexts[textNo].data.translatedText,{
  x: pagess[textNo].x,
  y: height - pagess[textNo].y,
  size: pagess[textNo].height,
  font: openSansFont,
})
}


// Serialize the PDFDocument to bytes (a Uint8Array)
const pdfBytes = await pdfDoc.save()

await writeFile("output.pdf",pdfBytes)

}