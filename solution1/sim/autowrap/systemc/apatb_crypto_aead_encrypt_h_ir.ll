; ModuleID = 'H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: noinline
define i32 @apatb_crypto_aead_encrypt_h_ir(i8* %c, i64* %clen, i8* %m, i64 %mlen, i8* %ad, i64 %adlen, i8* %nsec, i8* %npub, i8* %k, i64* %st) local_unnamed_addr #0 {
entry:
  %c_copy = alloca [48 x i8], align 512
  %clen_copy = alloca i64, align 512
  %m_copy = alloca [32 x i8], align 512
  %ad_copy = alloca [32 x i8], align 512
  %nsec_copy = alloca i8, align 512
  %npub_copy = alloca [16 x i8], align 512
  %k_copy = alloca [16 x i8], align 512
  %st_copy = alloca [5 x i64], align 512
  %0 = bitcast i8* %c to [48 x i8]*
  %1 = bitcast i8* %m to [32 x i8]*
  %2 = bitcast i8* %ad to [32 x i8]*
  %3 = bitcast i8* %npub to [16 x i8]*
  %4 = bitcast i8* %k to [16 x i8]*
  %5 = bitcast i64* %st to [5 x i64]*
  call fastcc void @copy_in([48 x i8]* %0, [48 x i8]* nonnull align 512 %c_copy, i64* %clen, i64* nonnull align 512 %clen_copy, [32 x i8]* %1, [32 x i8]* nonnull align 512 %m_copy, [32 x i8]* %2, [32 x i8]* nonnull align 512 %ad_copy, i8* %nsec, i8* nonnull align 512 %nsec_copy, [16 x i8]* %3, [16 x i8]* nonnull align 512 %npub_copy, [16 x i8]* %4, [16 x i8]* nonnull align 512 %k_copy, [5 x i64]* %5, [5 x i64]* nonnull align 512 %st_copy)
  %6 = getelementptr inbounds [48 x i8], [48 x i8]* %c_copy, i32 0, i32 0
  %7 = getelementptr inbounds [32 x i8], [32 x i8]* %m_copy, i32 0, i32 0
  %8 = getelementptr inbounds [32 x i8], [32 x i8]* %ad_copy, i32 0, i32 0
  %9 = getelementptr inbounds [16 x i8], [16 x i8]* %npub_copy, i32 0, i32 0
  %10 = getelementptr inbounds [16 x i8], [16 x i8]* %k_copy, i32 0, i32 0
  %11 = getelementptr inbounds [5 x i64], [5 x i64]* %st_copy, i32 0, i32 0
  %12 = call i32 @apatb_crypto_aead_encrypt_h_hw(i8* %6, i64* %clen_copy, i8* %7, i64 %mlen, i8* %8, i64 %adlen, i8* %nsec_copy, i8* %9, i8* %10, i64* %11)
  call fastcc void @copy_out([48 x i8]* %0, [48 x i8]* nonnull align 512 %c_copy, i64* %clen, i64* nonnull align 512 %clen_copy, [32 x i8]* %1, [32 x i8]* nonnull align 512 %m_copy, [32 x i8]* %2, [32 x i8]* nonnull align 512 %ad_copy, i8* %nsec, i8* nonnull align 512 %nsec_copy, [16 x i8]* %3, [16 x i8]* nonnull align 512 %npub_copy, [16 x i8]* %4, [16 x i8]* nonnull align 512 %k_copy, [5 x i64]* %5, [5 x i64]* nonnull align 512 %st_copy)
  ret i32 %12
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_in([48 x i8]* readonly, [48 x i8]* noalias align 512, i64* readonly, i64* noalias align 512, [32 x i8]* readonly, [32 x i8]* noalias align 512, [32 x i8]* readonly, [32 x i8]* noalias align 512, i8* readonly, i8* noalias align 512, [16 x i8]* readonly, [16 x i8]* noalias align 512, [16 x i8]* readonly, [16 x i8]* noalias align 512, [5 x i64]* readonly, [5 x i64]* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0a48i8([48 x i8]* align 512 %1, [48 x i8]* %0)
  call fastcc void @onebyonecpy_hls.p0i64(i64* align 512 %3, i64* %2)
  call fastcc void @onebyonecpy_hls.p0a32i8([32 x i8]* align 512 %5, [32 x i8]* %4)
  call fastcc void @onebyonecpy_hls.p0a32i8([32 x i8]* align 512 %7, [32 x i8]* %6)
  call fastcc void @onebyonecpy_hls.p0i8(i8* align 512 %9, i8* %8)
  call fastcc void @onebyonecpy_hls.p0a16i8([16 x i8]* align 512 %11, [16 x i8]* %10)
  call fastcc void @onebyonecpy_hls.p0a16i8([16 x i8]* align 512 %13, [16 x i8]* %12)
  call fastcc void @onebyonecpy_hls.p0a5i64([5 x i64]* align 512 %15, [5 x i64]* %14)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a48i8([48 x i8]* noalias align 512, [48 x i8]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [48 x i8]* %0, null
  %3 = icmp eq [48 x i8]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [48 x i8], [48 x i8]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [48 x i8], [48 x i8]* %1, i64 0, i64 %for.loop.idx1
  %5 = load i8, i8* %src.addr, align 1
  store i8 %5, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 48
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0i64(i64* noalias align 512, i64* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq i64* %0, null
  %3 = icmp eq i64* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = load i64, i64* %1, align 8
  store i64 %5, i64* %0, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a32i8([32 x i8]* noalias align 512, [32 x i8]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [32 x i8]* %0, null
  %3 = icmp eq [32 x i8]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [32 x i8], [32 x i8]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [32 x i8], [32 x i8]* %1, i64 0, i64 %for.loop.idx1
  %5 = load i8, i8* %src.addr, align 1
  store i8 %5, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 32
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0i8(i8* noalias align 512, i8* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq i8* %0, null
  %3 = icmp eq i8* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = load i8, i8* %1, align 1
  store i8 %5, i8* %0, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a16i8([16 x i8]* noalias align 512, [16 x i8]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [16 x i8]* %0, null
  %3 = icmp eq [16 x i8]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [16 x i8], [16 x i8]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [16 x i8], [16 x i8]* %1, i64 0, i64 %for.loop.idx1
  %5 = load i8, i8* %src.addr, align 1
  store i8 %5, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 16
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a5i64([5 x i64]* noalias align 512, [5 x i64]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [5 x i64]* %0, null
  %3 = icmp eq [5 x i64]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [5 x i64], [5 x i64]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [5 x i64], [5 x i64]* %1, i64 0, i64 %for.loop.idx1
  %5 = load i64, i64* %src.addr, align 8
  store i64 %5, i64* %dst.addr, align 8
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 5
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_out([48 x i8]*, [48 x i8]* noalias readonly align 512, i64*, i64* noalias readonly align 512, [32 x i8]*, [32 x i8]* noalias readonly align 512, [32 x i8]*, [32 x i8]* noalias readonly align 512, i8*, i8* noalias readonly align 512, [16 x i8]*, [16 x i8]* noalias readonly align 512, [16 x i8]*, [16 x i8]* noalias readonly align 512, [5 x i64]*, [5 x i64]* noalias readonly align 512) unnamed_addr #3 {
entry:
  call fastcc void @onebyonecpy_hls.p0a48i8([48 x i8]* %0, [48 x i8]* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0i64(i64* %2, i64* align 512 %3)
  call fastcc void @onebyonecpy_hls.p0a32i8([32 x i8]* %4, [32 x i8]* align 512 %5)
  call fastcc void @onebyonecpy_hls.p0a32i8([32 x i8]* %6, [32 x i8]* align 512 %7)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %8, i8* align 512 %9)
  call fastcc void @onebyonecpy_hls.p0a16i8([16 x i8]* %10, [16 x i8]* align 512 %11)
  call fastcc void @onebyonecpy_hls.p0a16i8([16 x i8]* %12, [16 x i8]* align 512 %13)
  call fastcc void @onebyonecpy_hls.p0a5i64([5 x i64]* %14, [5 x i64]* align 512 %15)
  ret void
}

declare i32 @apatb_crypto_aead_encrypt_h_hw(i8*, i64*, i8*, i64, i8*, i64, i8*, i8*, i8*, i64*)

define i32 @crypto_aead_encrypt_h_hw_stub_wrapper(i8*, i64*, i8*, i64, i8*, i64, i8*, i8*, i8*, i64*) #4 {
entry:
  %10 = bitcast i8* %0 to [48 x i8]*
  %11 = bitcast i8* %2 to [32 x i8]*
  %12 = bitcast i8* %4 to [32 x i8]*
  %13 = bitcast i8* %7 to [16 x i8]*
  %14 = bitcast i8* %8 to [16 x i8]*
  %15 = bitcast i64* %9 to [5 x i64]*
  call void @copy_out([48 x i8]* null, [48 x i8]* %10, i64* null, i64* %1, [32 x i8]* null, [32 x i8]* %11, [32 x i8]* null, [32 x i8]* %12, i8* null, i8* %6, [16 x i8]* null, [16 x i8]* %13, [16 x i8]* null, [16 x i8]* %14, [5 x i64]* null, [5 x i64]* %15)
  %16 = bitcast [48 x i8]* %10 to i8*
  %17 = bitcast [32 x i8]* %11 to i8*
  %18 = bitcast [32 x i8]* %12 to i8*
  %19 = bitcast [16 x i8]* %13 to i8*
  %20 = bitcast [16 x i8]* %14 to i8*
  %21 = bitcast [5 x i64]* %15 to i64*
  %22 = call i32 @crypto_aead_encrypt_h_hw_stub(i8* %16, i64* %1, i8* %17, i64 %3, i8* %18, i64 %5, i8* %6, i8* %19, i8* %20, i64* %21)
  call void @copy_in([48 x i8]* null, [48 x i8]* %10, i64* null, i64* %1, [32 x i8]* null, [32 x i8]* %11, [32 x i8]* null, [32 x i8]* %12, i8* null, i8* %6, [16 x i8]* null, [16 x i8]* %13, [16 x i8]* null, [16 x i8]* %14, [5 x i64]* null, [5 x i64]* %15)
  ret i32 %22
}

declare i32 @crypto_aead_encrypt_h_hw_stub(i8*, i64*, i8*, i64, i8*, i64, i8*, i8*, i8*, i64*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #4 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
