# Student Management System

## Loyihaning Maqsadi
Bu loyiha, o'quvchilarni boshqarish uchun dastur yaratishni maqsad qiladi. Foydalanuvchilar o'quvchilarni qo'shish, ularning ma'lumotlarini ko'rish, o'quvchilarni nomi bo'yicha izlash, va o'quvchilarga darslar va baholarni qo'shish imkoniyatiga ega bo'lishadi.

## Loyihaning Tuzilishi

### `Contact` Struct
Har bir o'quvchi yoki uning ota-onasining bog'lanish ma'lumotlarini saqlash uchun ishlatiladi:
- **`phone`**: char[] (Telefon raqami)
- **`email`**: char[] (Elektron pochta manzili)

### `Parent` Struct
O'quvchining ota-onasi haqida ma'lumotlarni saqlaydi:
- **`name`**: char[] (Ota-onaning ismi)
- **`contact`**: `Contact` (Ota-onaning bog'lanish ma'lumotlari)

### `Student` Struct
O'quvchi haqidagi asosiy ma'lumotlarni saqlaydi:
- **`first_name`**: char[] (O'quvchining ismi)
- **`last_name`**: char[] (O'quvchining familiyasi)
- **`age`**: int (Yosh)
- **`contact`**: `Contact` (O'quvchining bog'lanish ma'lumotlari)
- **`parent`**: `Parent` (O'quvchining ota-onasi haqida ma'lumot)

### `Lesson` Struct
Dars haqidagi ma'lumotlarni saqlaydi:
- **`id`**: int (Darsning ID raqami)
- **`name`**: char[] (Darsning nomi)

### `Score` Struct
O'quvchining baholari haqida ma'lumotni saqlaydi:
- **`lesson`**: `Lesson` (Dars)
- **`student`**: `Student` (O'quvchi)
- **`score`**: int (O'quvchining bir dars boyicha bahosi)

## Funksiyalar

1. **add_student**: Yangi o'quvchi qo'shadi.
2. **get_students**: Barcha o'quvchilarni ko'rsatadi.
3. **get_student_detail**: Belgilangan o'quvchining batafsil ma'lumotlarini ko'rsatadi.
4. **get_student_by_name**: O'quvchini ismi orqali izlash.
5. **add_lesson**: Yangi dars qo'shadi.
6. **add_score**: O'quvchiga dars bo'yicha baho qo'shadi.
7. **get_lesson_statistics**: Darslar bo'yicha statistika ko'rsatadi.
8. **menu**: Foydalanuvchiga menyu orqali tanlov qilish imkonini beradi.

## Dastur Ishlash Tamoyili

1. **Dastur boshlanganda menyu ko'rsatiladi**:
   Foydalanuvchi turli variantlarni tanlashi mumkin:
   ```
   1. Add Student
   2. View Students
   3. View Student Details
   4. Find Student by Name
   5. Add Lesson
   6. Add Score
   7. Get Lesson Statistics
   8. Exit
   Enter your choice:
   ```

2. **O'quvchi qo'shish**:
   Foydalanuvchi "Add Student" variantini tanlashi mumkin. Dastur foydalanuvchidan o'quvchining ismi, familiyasi, yoshi, telefon raqami, elektron pochta manzili, va ota-onasining ma'lumotlarini so'raydi. 
   - Misol:
     ```
     Enter first name: John
     Enter last name: Doe
     Enter age: 20
     Enter phone: 1234567890
     Enter email: john.doe@example.com
     Enter parent's name: Jane Doe
     Enter parent's phone: 0987654321
     Enter parent's email: jane.doe@example.com
     Student added successfully!
     ```

3. **Barcha o'quvchilarni ko'rsatish**:
   Foydalanuvchi "View Students" variantini tanlasa, barcha o'quvchilar ro'yxatdagi ma'lumotlar bilan ko'rsatiladi:
   - Misol:
     ```
     ID   | First Name | Last Name | Age | Phone        | Email                    | Parent's Name | Parent's Phone | Parent's Email
     ----------------------------------------------------------------------------------------------------------
     1    | John       | Doe       | 20  | 1234567890   | john.doe@example.com      | Jane Doe      | 0987654321     | jane.doe@example.com
     ```

4. **O'quvchining batafsil ma'lumotlarini ko'rish**:
   Foydalanuvchi "View Student Details" variantini tanlasa, o'quvchining ID raqami kiritiladi va o'sha o'quvchining batafsil ma'lumotlari ko'rsatiladi:
   - Misol:
     ```
     Enter student ID to get: 1
     First Name: John
     Last Name: Doe
     Age: 20
     Phone: 1234567890
     Email: john.doe@example.com
     Parent's Name: Jane Doe
     Parent's Phone: 0987654321
     Parent's Email: jane.doe@example.com
     ```

5. **O'quvchini ismi bo'yicha izlash**:
   Foydalanuvchi "Find Student by Name" variantini tanlasa, o'quvchining ismi kiritiladi va o'sha ismga mos o'quvchi ro'yxatda ko'rsatiladi.

6. **Yangi dars qo'shish**:
   Foydalanuvchi "Add Lesson" variantini tanlasa, yangi dars qo'shish imkoniyati beriladi. Dars nomi va ID raqami kiritiladi.

7. **O'quvchiga baho qo'shish**:
   Foydalanuvchi "Add Score" variantini tanlasa, o'quvchi va darsni tanlab, baho qo'shish mumkin.

8. **Darslar bo'yicha statistika ko'rsatish**:
   Foydalanuvchi "Get Lesson Statistics" variantini tanlasa, darslar bo'yicha statistik ma'lumotlar ko'rsatiladi.

9. **Dasturni yakunlash**:
   Foydalanuvchi "Exit" variantini tanlasa, dasturdan chiqiladi.

## Loyihani Ishga Tushurish
1. `student_management.c` faylini kompyuteringizda saqlang.
2. C kompilyatori orqali quyidagi buyruqni ishlating:
   ```
   gcc student_management.c -o student_management
   ./student_management
   ```
3. Dastur sizga menyu orqali o'quvchilarni boshqarish imkonini beradi.
