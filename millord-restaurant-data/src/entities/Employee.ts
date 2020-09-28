import { User } from './User'


export class Employee extends User {
<<<<<<< HEAD
  private _code?: string
  constructor() {
    super()
  }

  get code(): string | undefined {
    return this._code
  }

  set code(value: string | undefined) {
    this._code = value
  }
=======
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

>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b
}