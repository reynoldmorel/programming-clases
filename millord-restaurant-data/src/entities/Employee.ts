import { User } from './User'


export class Employee extends User {
  private code?: string
  constructor(id?: string) {
    super(id)
  }

  public Employee(id: string) {
    return id
  }

  public getCode() {
    return this.code
  }

  public setCode(code: string) {
    return this.code = code
  }

}