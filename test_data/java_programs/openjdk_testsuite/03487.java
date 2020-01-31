



public class DeepNestedFinally {
   static public int func(int i) {
    try {
        if(i == 1) return 1;
    } finally {
        try {
            if(i == 2) return 2;
        } finally {
            try {
                if(i == 3) return 3;
            } finally {
                try {
                    if(i == 4) return 4;
                } finally {
                    try {
                        if(i == 5) return 5;
                    } finally {
                        try {
                            if(i == 6) return 6;
                        } finally {
                            try {
                                if (i == 7) return 7;
                            } finally {
                                int x = 0;
                                x += 1;
                                x += 2;
                                x += 3;
                                x += 4;
                                x += 5;
                                x += 6;
                                x += 7;
                                x += 8;
                                x += 9;
                            }
                        }
                    }
                }
             }
         }
      }
      return 0;
   }
}
