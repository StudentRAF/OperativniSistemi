Operativni sistemi - Vežba - Zadatak 1
---

Implementacija fs komande koja vraća informacije za filesystem operativnog sistema xv6.

<details>
  <summary><h4>Implementirani flag-ovi</h4></summary>

- -db   (ili --data-block) - ispisuje ukupan broj blokova na data delu diska
- -ob   (ili --occupied-block) - ispisuje ukupan broj popunjenih blokova na disku (gleda se samo data deo)
- -fb   (ili --free-block) - ispisuje ukupan broj slobodnoh blokova na disku
- -ec   (ili --entry-count) - ispisuje ukupan broj fajlova, direktorijuma i uređaja na disku
- -dc   (ili --directory-count) - ispisuje ukupan broj direktorijuma na disku
- -fc   (ili --file-count) - ispisuje ukupan broj fajlova na disku
- -devc (ili --device-count) - ispisuje ukupan broj uređaja na disku
- -fs   (ili --files-size) - ispisuje ukupnu veličinu u bajtovima koju sadrže svi fajlovi
- -fos  (ili --files-occupied-size) - ispisuje ukupnu veličinu u bajtovima koju zauzimaju fajlovi na disku

</details>