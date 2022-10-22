import express from 'express';
import { work } from './utils.js';
export const router = express.Router();
import multiparty from 'multiparty'

// import {func} from 'utils';

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});


router.post('/',(req, res) => {
  let form = new multiparty.Form();

  form.parse(req, async (err, fields, files) => {
    console.log(err,fields, files);
    console.log(files.filename[0].path);
    console.log(fields.from);
    // slks.ds
    await work(files.filename[0].path,fields.from[0],fields.to[0]);
    console.log("DONEE")
    res.download("output.pdf");
  });
  // console.log(req.body, req.files);
  // var file = req.files.file;
  // console.log(file.name);
  // console.log(file.type);
  
  // res.status(200).send('OK');
});

