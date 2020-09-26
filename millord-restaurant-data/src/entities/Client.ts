import { User } from './User'


export class Client extends User {
  private code?: string
  constructor(id?: string) {
    super(id)
  }

  public Client(id: string) {
    return id
  }

  public getCode() {
    return this.code
  }

  public setCode(code: string) {
    return this.code = code
  }

}