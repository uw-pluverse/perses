package main;

import "reflect";

func main() {};

var typeUint64 = reflect.ValueOf(       0 ).Type();

var x = reflect.StructOf([]reflect.StructField{
 {Name: "F1", Type: reflect.ArrayOf(4, typeUint64)},
 {Name: "F5", Type: reflect.ArrayOf(7,
  reflect.StructOf([]reflect.StructField{
   {Name: "F1", Type: reflect.StructOf([]reflect.StructField{
    {Name: "F1", Type: reflect.StructOf([]reflect.StructField{
     {Name: "F11", Type: reflect.StructOf([]reflect.StructField{
      {Name: "F6", Type: reflect.StructOf([]reflect.StructField{
       {Name: "F1", Type: reflect.StructOf([]reflect.StructField{
        {Name: "F7", Type: reflect.StructOf([]reflect.StructField{
         {Name: "F0", Type: reflect.StructOf([]reflect.StructField{
          {Name: "F1", Type: reflect.SliceOf(reflect.StructOf([]reflect.StructField{

          }))},
          {Name: "F5", Type: reflect.StructOf([]reflect.StructField{
           {Name: "F3", Type: reflect.StructOf([]reflect.StructField{
            {Name: "F8", Type: reflect.ArrayOf(16,
             reflect.ArrayOf(1,
              reflect.StructOf([]reflect.StructField{
               {Name: "F1", Type: reflect.ArrayOf(32,
                reflect.StructOf([]reflect.StructField{
                 {Name: "F5", Type: reflect.StructOf([]reflect.StructField{
                  {Name: "F0", Type: typeUint64},
                 })},
                }))},
               {Name: "F6", Type: reflect.ArrayOf(115,
                reflect.StructOf([]reflect.StructField{
                 {Name: "F8", Type: typeUint64},
                }))},
              })))},
           })},
          })},
         })},
        })},
       })},
      })},
     })},
    })},
   })},
  })),
 },
});
