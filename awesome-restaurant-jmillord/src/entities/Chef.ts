import { User } from './User'


export class Chef extends User {
  constructor() { 
    super()
  }
  
  get id(): string | undefined {
    return this._id
  }


}