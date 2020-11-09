import express from 'express'
import morgan from 'morgan'
import cors from 'cors'
import {createConnection} from 'typeorm'

const app  = express()
createConnection()


// middlewares

app.use(cors())
app.use(morgan('dev'))
app.use(express.json())

const port = 3000

app.listen(port, ()=>  console.log(`Server running on ${port}`))
